#include <iostream>
#include <vector>

using namespace std;
class Robot {
private:
    string directions[4]={ {"East"}, {"North"}, {"West"}, {"South"}};
    int x, y, w, h;
    int curr_pos;
public:
    Robot(int width, int height) : w(width),  h(height){
        this->x = 0;
        this->y = 0;
        curr_pos = 0;
    }

    void move(int num) {

        num %= (2* (w-1 + h-1));
        if (num == 0 && x == 0 && y == 0) {
            curr_pos = 3;
        }

        while (num > 0) {
            switch(curr_pos) {
                case 0:
                    if (x + num < w) {
                        x += num;
                        num = 0;
                    } else {
                        num -= (w-1-x);
                        x = w - 1;
                        curr_pos = (curr_pos + 1) % 4;
                    }
                    break;
                case 1:
                    if (y + num < h) {
                        y += num;
                        num = 0;
                    } else {
                        num -= (h-1-y);
                        y = h - 1;
                        curr_pos = (curr_pos + 1) % 4;

                    }
                    break;
                case 2:
                    if (x - num >= 0) {
                        x -= num;
                        num = 0;
                    } else {
                        num -= x;
                        x = 0;
                        curr_pos = (curr_pos + 1) % 4;
                    }
                    break;
                case 3:
                    if (y - num >= 0) {
                        y -= num;
                        num = 0;
                    } else {
                        num -= y;
                        y = 0;
                        curr_pos = (curr_pos + 1) % 4;
                    }
                    break;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return directions[curr_pos];
    }

    void setRobot(int x, int y, int pos) {
        this->x = x;
        this->y = y;
        this->curr_pos = pos;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

void printRobotStatus(Robot* r) {
    vector<int> v = r->getPos();
    cout << v[0] << ", " << v[1] << "---";
    cout << r->getDir() << endl;
}
int main() {
    auto* obj = new Robot(20, 14);
    obj->setRobot(19, 3, 1);
    obj->move(45);
    printRobotStatus(obj);
    obj->move(37);
    printRobotStatus(obj);
    obj->move(39);
    printRobotStatus(obj);
    return 0;
}
