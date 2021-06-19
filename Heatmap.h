//
// Created by ahmed on 15.06.2021.
//

#ifndef OPTIMISER_HEATMAP_H
#define OPTIMISER_HEATMAP_H

#include <QImage>
#include <QPixmap>
#include <QLabel>

typedef std::vector<double> cevd;
typedef std::vector<cevd> cevd2;

class HeatMap : public QLabel {
public:
    HeatMap(cevd2 data, int leng = 500, int hght = 400);
    void setData(cevd2 data);

private:
    double maximum(cevd2 data);
    double minimum(cevd2 data);
    double minD;
    double maxD;
    QImage* imageD;
    QPixmap mainFrame;
    int wdth;
    int hght;
};


#endif //OPTIMISER_HEATMAP_H
