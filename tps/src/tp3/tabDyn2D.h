#ifndef TABDYN2D_H
#define TABDYN2D_H

class tabDyn2D
{
    private:
        int nbLignes;
        int nbCol;
        double* values;
    public:
        tabDyn2D(int nbLignes, int nbCol);
        tabDyn2D(const tabDyn2D &source);
        ~tabDyn2D();
        void affiche();

        tabDyn2D& operator=(const tabDyn2D& source);
        tabDyn2D& operator+=(const tabDyn2D& source);
        tabDyn2D& operator+=(const double value);
};

#endif // TABDYN2D_H
