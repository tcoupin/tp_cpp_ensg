#ifndef TABLEAUDYN_H
#define TABLEAUDYN_H


class TableauDyn
{
    public:
        TableauDyn(long int taille);
        TableauDyn(const TableauDyn &source);
        ~TableauDyn();
        void print();
        void input();
        float sum();
        float mean();
        TableauDyn& operator=(const TableauDyn& tab);
        void write(char* file);
        static TableauDyn read(char* file);
        void writeb(char* file);
        static TableauDyn readb(char* file);

    protected:

    private:
        long int nbmax;
        float* values;
        long int nbvalues;
};

#endif // TABLEAUDYN_H
