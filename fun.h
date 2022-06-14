#pragma once
#include "vector"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
namespace fun{
    // Интерфейс "Геометрическая фигура".
    class IGeoFig {
    public :
        // Площадь.
        virtual double square () = 0 ;
        // Периметр.
        virtual double perimeter () = 0 ;
    } ;
// Вектор
    class CVector2D {
    public :
        double x, y;
    } ;
// Интерфейс "Физический объект".
    class IPhysObject {
    public :
        // Масса, кг.
        virtual double mass () const = 0 ;
        // Координаты центра масс, м.
        virtual CVector2D position () = 0 ;
        // Сравнение по массе.
        virtual bool operator == ( const IPhysObject& ob ) const = 0 ;
        // Сравнение по массе.
        virtual bool operator < ( const IPhysObject& ob ) const = 0 ;
    } ;
// Интерфейс "Отображаемый"
    class IPrintable {
    public :
        // Отобразить на экране
        // (выводить в текстовом виде параметры фигуры).
        virtual void draw () = 0 ;
    } ;
// Интерфейс для классов, которые можно задать через диалог с пользователем.
    class IDialogInitiable {
// Задать параметры объекта с помощью диалога с пользователем.
        virtual void initFromDialog () = 0 ;
    } ;
// Интерфейс "Класс"
    class BaseCObject {
    public :
        //// Имя класса (типа данных).
        virtual const char * classname () = 0 ;
        //// Размер занимаемой памяти.
        virtual unsigned int size () = 0 ;
    } ;

    class BaseFigure:
            public IGeoFig,
            public IPhysObject,
            public IPrintable,
            public IDialogInitiable,
            public BaseCObject {
    };

    class Circle: BaseFigure {

    protected:
        double positioned_x, positioned_y;
        double r;
        double mass_;


    public:
        Circle();
        void initFromDialog() override;
        double square() override;
        double perimeter() override;
        double mass() const override;
        CVector2D position() override;
        bool operator == (const IPhysObject& obj) const override;
        bool operator < (const IPhysObject& obj) const override;
        void draw() override;
        const char* classname() override;
        unsigned int size() override;

    };



    class EqTriangle: BaseFigure {

    protected:
        double positioned_x, positioned_y, edge_, mass_;

    public:
        EqTriangle();
        void initFromDialog() override;
        double square() override;
        double perimeter() override;
        double mass() const override;
        CVector2D position() override;
        bool operator == (const IPhysObject& obj) const override;
        bool operator < (const IPhysObject& obj) const override;
        void draw() override;
        const char* classname() override;
        unsigned int size() override;
    };
    class Menu {
    private:
        vector<BaseFigure*> pointers;
        int chosen;
        double sum_perimeters = 0;
        double sum_squares = 0;
        double sum_mass = 0;
        unsigned int sum_size = 0;

    public:
        Menu();
        void choseFunc();
        template<class Figure>
        void createFigure(){
            auto* figure = new Figure();
            figure->initFromDialog();
            sum_squares+=figure->square();
            sum_perimeters+=figure->perimeter();
            sum_mass+=figure->mass();
            sum_size+=figure->size();
            pointers.push_back((BaseFigure*)figure);
        }
        void runFunc();

    };

}