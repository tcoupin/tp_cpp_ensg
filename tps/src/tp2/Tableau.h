#ifndef TABLEAU_H
#define TABLEAU_H


class Tableau
{
    public:
        Tableau();
        ~Tableau();
        void push(float value);
        void pushUnsecure(float value);
        void print();
        void printAll();
        void input();
        float sum();
        float mean();
        long int length();
        float get(long int i);
        Tableau operator+(Tableau tab);
        void sort(bool asc = true);

    protected:

    private:
        static const long int nbmax = 6;
        float values[nbmax];
        long int nbvalues;
};

#endif // TABLEAU_H

