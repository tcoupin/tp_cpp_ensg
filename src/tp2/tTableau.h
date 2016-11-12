#ifndef TTABLEAU_H
#define TTABLEAU_H


class tTableau
{
    public:
        tTableau();
        virtual ~tTableau();
        void push(float value);
        void pushUnsecure(float value);
        void print();
        void printAll();
        void input();
        float sum();
        float mean();
        long int length();
        float get(long int i);
        tTableau operator+(tTableau tab);
        void sort();

    protected:

    private:
        static const long int nbmax = 6;
        float values[nbmax];
        long int nbvalues;
};

#endif // TTABLEAU_H

