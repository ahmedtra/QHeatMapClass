//
// Created by ahmed on 15.06.2021.
//

#include "./HeatMap.h"

HeatMap::HeatMap(cevd2 data, int leng, int hight)
{
    wdth = leng;
    hght = hight;
    setData(data);
};



void HeatMap::setData(cevd2 data){
    imageD = new QImage(wdth, hght, QImage::Format_RGB32);

    minD = minimum(data);
    maxD = maximum(data);

    for(int z = 0; z < hght; z++) {
        for(int x = 0; x < wdth; x++) {
            int i = (int) ((float) z / hght * data.size());
            int j = (int) ((float) x / wdth * data[0].size());
            int Rv = 0;
            if (maxD>minD) Rv = (int) (255 * data[i][j] / (maxD - minD));
            if (Rv > 0){
                Rv = Rv;
            }
            QRgb value = qRgb(Rv, 0, 0);
            imageD->setPixel(x, z, value);
        }
    };

    resize(wdth, hght);

    mainFrame = QPixmap::fromImage(*imageD);

    this->setPixmap(mainFrame);

    this->show();
}

double HeatMap::maximum(cevd2 data){
    double max = data[0][0];
    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[0].size(); j++) {
            if(data[i][j] > max) max = data[i][j];
        }
    };
    return max;
}

double HeatMap::minimum(cevd2 data){
    double min = data[0][0];
    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[0].size(); j++) {
            if(data[i][j] < min) min = data[i][j];
        }
    };
    return min;
}
