#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Player {
private:
  string name;
  int hp;
  int ammo;
  int x, y;

  int clamp(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
  }

public:
  Player(string n, int h, int a)
    : name(n), hp(clamp(h,0,100)), ammo(a), x(0), y(0) {}

  Player& move(int dx, int dy) {
    x += dx; y += dy;
    return *this;
  }

  Player& fire(int rounds) {
    ammo -= rounds;
    if (ammo < 0) ammo = 0;
    return *this;
  }

  Player& take_damage(int dmg) {
    hp = clamp(hp - dmg, 0, 100);
    return *this;
  }

  Player& reload(int rounds) {
    ammo += rounds;
    return *this;
  }

  Player& heal(int pts) {
    hp = clamp(hp + pts, 0, 100);
    return *this;
  }

  string status() const {
    ostringstream os;
    os << name << " HP=" << hp
       << "  Ammo=" << ammo
       << " Pos=(" << x << "," << y << ")";
    return os.str();
  }
};

int main() {
  Player p{"Daniels", 100, 30};
  cout << p.status() << "\n";
  p.move(1,0).fire(10).take_damage(25).reload(15).heal(10);
  cout << p.status() << "\n";
}
