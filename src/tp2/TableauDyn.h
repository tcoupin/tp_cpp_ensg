#ifndef TABLEAUDYN_H
#define TABLEAUDYN_H


class TableauDyn
{
    public:
        TableauDyn(long int taille);
        TableauDyn(const TableauDyn &);
        ~TableauDyn();
        void print();
        void input();
        float sum();
        float mean();
        TableauDyn& operator=(const TableauDyn& tab);

    protected:

    private:
        long int nbmax;
        float* values;
        long int nbvalues;
};

#endif // TABLEAUDYN_H
