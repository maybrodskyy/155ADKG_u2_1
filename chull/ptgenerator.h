#ifndef PTGENERATOR_H
#define PTGENERATOR_H
#include <vector>
#include <QPoint>
#include <QSize>

class ptgenerator
{
public:
    ptgenerator();
    static std::vector<QPoint> generateCluster(int &n,QSize &size);
    static std::vector<QPoint> generateRandom(int &n,QSize &size);
    static std::vector<QPoint> generateGrid(int &n,QSize &size);

};

#endif // PTGENERATOR_H
