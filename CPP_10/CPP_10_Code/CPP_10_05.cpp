#include <iostream>
#include <string>
using namespace std;

// Class Definitions without Polymorphism
class Player {
private:
    string name;
    int number;
    string position;
public:
    Player(string n, int num, string pos) : name(n), number(num), position(pos) {}
    void display() const {
        cout << "Player: " << name << ", Number: " << number << ", Position: " << position << endl;
    }
};

class Coach {
private:
    string name;
    string strategy;
public:
    Coach(string n, string strat) : name(n), strategy(strat) {}
    void display() const {
        cout << "Coach: " << name << ", Strategy: " << strategy << endl;
    }
};

class Ball {
private:
    string brand;
    string type;
public:
    Ball(string b, string t) : brand(b), type(t) {}
    void display() const {
        cout << "Ball: " << brand << ", Type: " << type << endl;
    }
};

class Referee {
private:
    string name;
    int experience;
public:
    Referee(string n, int exp) : name(n), experience(exp) {}
    void display() const {
        cout << "Referee: " << name << ", Experience: " << experience << " years" << endl;
    }
};

class Goal {
private:
    string location;
    float width;
public:
    Goal(string loc, float w) : location(loc), width(w) {}
    void display() const {
        cout << "Goal: " << location << ", Width: " << width << " meters" << endl;
    }
};

// Class Definitions with Polymorphism
class GameEntity {
public:
    virtual void display() const = 0;
    virtual ~GameEntity() {}
};

class PlayerEntity : public GameEntity {
private:
    string name;
    int number;
    string position;
public:
    PlayerEntity(string n, int num, string pos) : name(n), number(num), position(pos) {}
    void display() const override {
        cout << "Player: " << name << ", Number: " << number << ", Position: " << position << endl;
    }
};

class CoachEntity : public GameEntity {
private:
    string name;
    string strategy;
public:
    CoachEntity(string n, string strat) : name(n), strategy(strat) {}
    void display() const override {
        cout << "Coach: " << name << ", Strategy: " << strategy << endl;
    }
};

class BallEntity : public GameEntity {
private:
    string brand;
    string type;
public:
    BallEntity(string b, string t) : brand(b), type(t) {}
    void display() const override {
        cout << "Ball: " << brand << ", Type: " << type << endl;
    }
};

class RefereeEntity : public GameEntity {
private:
    string name;
    int experience;
public:
    RefereeEntity(string n, int exp) : name(n), experience(exp) {}
    void display() const override {
        cout << "Referee: " << name << ", Experience: " << experience << " years" << endl;
    }
};

class GoalEntity : public GameEntity {
private:
    string location;
    float width;
public:
    GoalEntity(string loc, float w) : location(loc), width(w) {}
    void display() const override {
        cout << "Goal: " << location << ", Width: " << width << " meters" << endl;
    }
};

int main() {
    // Without Polymorphism: Separate Arrays
    cout << "=== Without Polymorphism ===\n";

    Player players[] = {
        Player("Ali", 10, "Forward"),
        Player("Hassan", 7, "Midfielder")
    };
    Coach coaches[] = {
        Coach("Reza", "Defensive"),
        Coach("Majid", "Offensive")
    };
    Ball balls[] = {
        Ball("Adidas", "Official"),
        Ball("Nike", "Training")
    };
    Referee referees[] = {
        Referee("Ahmad", 5),
        Referee("Kaveh", 8)
    };
    Goal goals[] = {
        Goal("North End", 7.32),
        Goal("South End", 7.32)
    };

    cout << "\nPlayers:\n";
    for (int i = 0; i < 2; i++) {
        players[i].display();
    }

    cout << "\nCoaches:\n";
    for (int i = 0; i < 2; i++) {
        coaches[i].display();
    }

    cout << "\nBalls:\n";
    for (int i = 0; i < 2; i++) {
        balls[i].display();
    }

    cout << "\nReferees:\n";
    for (int i = 0; i < 2; i++) {
        referees[i].display();
    }

    cout << "\nGoals:\n";
    for (int i = 0; i < 2; i++) {
        goals[i].display();
    }

    // With Polymorphism: Single Array
    cout << "\n=== With Polymorphism ===\n";
    GameEntity* entities[] = {
        new PlayerEntity("Ali", 10, "Forward"),
        new PlayerEntity("Hassan", 7, "Midfielder"),
        new CoachEntity("Reza", "Defensive"),
        new CoachEntity("Majid", "Offensive"),
        new BallEntity("Adidas", "Official"),
        new BallEntity("Nike", "Training"),
        new RefereeEntity("Ahmad", 5),
        new RefereeEntity("Kaveh", 8),
        new GoalEntity("North End", 7.32),
        new GoalEntity("South End", 7.32)
    };

    cout << "\nAll Entities:\n";
    for (int i = 0; i < 10; i++) {
        entities[i]->display();
        delete entities[i]; // Clean up memory
    }

    return 0;
}