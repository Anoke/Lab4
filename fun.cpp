#include <cmath>
#include "fun.h"
#include <iostream>
#include <algorithm>
namespace fun {
    Circle::Circle() {
        positioned_x = 0, positioned_y = 0, r = 0, mass_ = 0;
    }

    void Circle::initFromDialog() {
        cout << "Enter circle's coords {x: y} :\n";
        cin >> positioned_x >> positioned_y;
        cout << "Enter circle's r : \n";
        cin >> r;
        cout << "Enter circle's mass :\n";
        cin >> mass_;
    };

    double Circle::square() {
        return r * r * M_PI;
    };

    double Circle::perimeter() {
        return 2 * r * M_PI;
    };

    double Circle::mass() const {
        return mass_;
    };

    CVector2D Circle::position() {
        CVector2D answer{};
        answer.x = positioned_x;
        answer.y = positioned_y;
        return answer;
    };

    bool Circle::operator==(const IPhysObject &obj) const {
        return (mass_ == obj.mass());
    };

    bool Circle::operator<(const IPhysObject &obj) const {
        return (mass_ < obj.mass());
    };

    void Circle::draw() {
        cout << "Coords of center: (" << positioned_x << ", " << positioned_y << ")\n";
        cout << "r = : " << r << "\n";
        cout << "Mass: " << mass_ << "\n";
    }

    const char *Circle::classname() {
        return typeid(this).name();
    };

    unsigned int Circle::size() {
        return sizeof *this;
    };


    EqTriangle::EqTriangle(){
        positioned_x = 0, positioned_y = 0, edge_ = 0, mass_ = 0;
    }

    void EqTriangle::initFromDialog() {
        cout << "Enter equilateral triangle's coords [x, y] :\n";
        cin >> positioned_x >> positioned_y;
        cout << "Enter equilateral triangle's edges [edge] : \n";
        cin >> edge_;
        cout << "Enter equilateral triangle's mass :\n";
        cin >> mass_;
    }

    double EqTriangle::square() {
        return edge_*sqrt(3)/4;
    };

    double EqTriangle::perimeter() {
        return edge_*3;
    };

    double EqTriangle::mass() const {
        return mass_;
    };

    CVector2D EqTriangle::position() {
        CVector2D answer;
        answer.x = positioned_x;
        answer.y = positioned_y;
        return answer;
    };

    bool EqTriangle::operator==(const IPhysObject &obj) const {
        return (mass_ == obj.mass());
    };

    bool EqTriangle::operator<(const IPhysObject &obj) const {
        return (mass_ < obj.mass());
    }

    void EqTriangle::draw() {
        cout << "Coords of center: (" << positioned_x << ", " << positioned_y << ")\n";
        cout << "Edge x 3 = : " << edge_ << "\n";
        cout << "Mass: " << mass_ << "\n";
    }

    const char *EqTriangle::classname() {
        return typeid(this).name();
    };

    unsigned int EqTriangle::size() {
        return sizeof *this;
    };

    Menu::Menu() {
        chosen = 0;
    };

    void Menu::choseFunc() {
        std::cout << "Choose type of the operation:\n";
        std::cout << "1 - Add Circle\n";
        std::cout << "2 - Add equilateral triangle\n";
        std::cout << "3 - Show all figures\n";
        std::cout << "4 - Show total square of figures\n";
        std::cout << "5 - Show total perimeter of figures\n";
        std::cout << "6 - Show center mass of all figures\n";
        std::cout << "7 - Show total memory that objects occupy\n";
        std::cout << "8 - Sort all figures by mass\n\n";
        std::cin >> chosen;
    };

    void Menu::runFunc() {
        switch (chosen) {

            case 0:
                cout << "Type of operation not found!\n";
                break;

            case 1:
                createFigure<Circle>();
                break;

            case 2:
                createFigure<EqTriangle>();
                break;

            case 3:
                cout << "-----\nAll figures: " << endl;
                for (int i = 0; i < pointers.size(); ++i) {
                    cout << "Number: " << i + 1 << endl;
                    cout << "---start---" << endl;
                    pointers[i]->draw();
                    cout << "----end----" << endl;
                }
                cout << endl << "-----------" << endl;
                break;
            case 4:
                cout << "Total square:" << endl;
                cout << sum_squares << endl;
                break;

            case 5:
                cout << "Total perimeter:" << endl;
                cout << sum_perimeters << endl;
                break;

            case 6:
                cout << "Total center mass:" << endl;
                cout << sum_mass << endl;
                break;

            case 7:
                cout << "Total memory used:" << endl;
                cout << sum_size << endl;
                break;

            case 8:
                sort(pointers.begin(), pointers.end(),
                     [](BaseFigure *lhs, BaseFigure *rhs) {
                         return *lhs < *rhs;
                     }
                );
                break;
            default:
                cout << "Unknown function" << endl;
                break;
        }
    };

}