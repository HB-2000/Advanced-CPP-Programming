import re
import sys

def escape_html_entities(text):
    """Replace <, >, and & with their HTML entities."""
    replacements = {
        '&': '&amp;',
        '<': '&lt;',
        '>': '&gt;',
        
    }
    for char, entity in replacements.items():
        text = text.replace(char, entity)
    return text

def update_html_file(input_file, output_file=None):
    """
    Read an HTML file, replace <, >, and & in <code> blocks using regex,
    and update the file.
    """
    try:
        # Read the HTML file
        with open(input_file, 'r', encoding='utf-8') as file:
            html_content = file.read()

        # Regex pattern to find <code>...</code> blocks
        code_block_pattern = r'(<code>)(.*?)(</code>)'
        
        # List to store found blocks (for debugging)
        found_blocks = []

        # Replacement function to process code block content
        def replace_code_block(match):
            # Extract content inside <code>...</code>
            code_open = match.group(1)  # <code>
            code_content = match.group(2)  # Code content
            code_close = match.group(3)  # </code>
            
            # Store block for debugging
            found_blocks.append(code_content[:50] + '...' if len(code_content) > 50 else code_content)
            
            # Replace <, >, and & in code content
            updated_content = escape_html_entities(code_content)
            
            # Rebuild block
            return f"{code_open}{updated_content}{code_close}"

        # Replace all code blocks in the file
        updated_html = re.sub(code_block_pattern, replace_code_block, html_content, flags=re.DOTALL)

        # Print debug information
        if found_blocks:
            print(f"Number of <code> blocks found: {len(found_blocks)}")
            print("Sample block contents:")
            for i, block in enumerate(found_blocks, 1):
                print(f"Block {i}: {block}")
        else:
            print("No <code> blocks found. Please check the HTML file structure.")

        if updated_html == html_content:
            print("No changes applied (no <, >, & characters found or already replaced).")
            return

        # Set output file (default to input file if not specified)
        output_file = output_file or input_file

        # Save updated file
        with open(output_file, 'w', encoding='utf-8') as file:
            file.write(updated_html)
        print(f"File successfully updated: {output_file}")

    except FileNotFoundError:
        print(f"Error: File {input_file} not found. Please check the file path.")
    except Exception as e:
        print(f"Error processing file: {str(e)}")

if __name__ == "__main__":
    # Check for command-line argument
    if len(sys.argv) != 2:
        print("Usage: python update_html_entities_regex_fixed.py <input_html_file>")
        sys.exit(1)
    
    # Get input file from command-line argument
    input_html = sys.argv[1]
    update_html_file(input_html)