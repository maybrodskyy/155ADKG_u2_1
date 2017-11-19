#ifndef PTGENERATOR_H
#define PTGENERATOR_H
#include <vector>
#include <QPoint>

class ptgenerator
{
public:
    ptgenerator();
    static std::vector<QPoint> generateCluster(int n);
    static std::vector<QPoint> generateRandom(int n);
    static std::vector<QPoint> generateGrid(int n);

};

#endif // PTGENERATOR_H
