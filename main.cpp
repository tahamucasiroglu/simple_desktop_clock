

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <ctime>
#include <string>

using namespace std;


int main()
{
    string windowName = "Saat";
    cv::namedWindow(windowName);
    cv::Mat clock(640, 640, CV_8UC3);//3 kanallı 640 a 640 bir pencere oluşturttuk
    clock = cv::Scalar(0, 0, 0);//arkaplanı siyah yaptırdık

    cv::Mat cclock;

    cv::circle(clock, cv::Point(clock.cols/2, 280), 270, cv::Scalar(200,200,200), 3);
    cv::putText(clock, "12", cv::Point(310 + 240 * sin(180 * M_PI / 180), 290 + 240 * cos(180 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255,125 ,125 ), 1);
    cv::putText(clock, "1", cv::Point(310 + 240 * sin(150 * M_PI / 180), 290 + 240 * cos(150 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "2", cv::Point(310 + 240 * sin(120 * M_PI / 180), 290 + 240 * cos(120 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "3", cv::Point(310 + 240 * sin(90 * M_PI / 180), 290 + 240 * cos(90 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "4", cv::Point(310 + 240 * sin(60 * M_PI / 180), 290 + 240 * cos(60 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "5", cv::Point(310 + 240 * sin(30 * M_PI / 180), 290 + 240 * cos(30 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "6", cv::Point(310 + 240 * sin(0 * M_PI / 180), 290 + 240 * cos(0 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "7", cv::Point(310 + 240 * sin(330 * M_PI / 180), 290 + 240 * cos(330 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "8", cv::Point(310 + 240 * sin(300 * M_PI / 180), 290 + 240 * cos(300 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "9", cv::Point(310 + 240 * sin(270 * M_PI / 180), 290 + 240 * cos(270 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "10", cv::Point(310 + 240 * sin(240 * M_PI / 180), 290 + 240 * cos(240 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);
    cv::putText(clock, "11", cv::Point(310 + 240 * sin(210 * M_PI / 180), 290 + 240 * cos(210 * M_PI / 180)), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 1.7, cv::Scalar(255, 125, 125), 1);

    


    clock.copyTo(cclock);//cclock a 1 den 12 y saat sayıları ve çemberi kayıt ettik ki sonradan ekran silmede kullanabilelim
    while (true)
    {
        
        time_t now = time(0);// time kütüphanesi ile bilgisayardan zaamnı alma
        tm* time = localtime(&now);
        int yil = time->tm_year + 1900;
        int ay = time->tm_mon + 1;
        int gun = time->tm_mday;
        int saat =  time->tm_hour;
        int dakika = time->tm_min;
        int saniye =  time->tm_sec;
        string tarih,dat1=":",dat2="/";
        

        if (saat < 10) {
            tarih += "0";
            tarih += to_string(saat);
        }
        else {
            tarih += to_string(saat);
        }
        tarih += dat1;
        if (dakika < 10) {
            tarih += "0";
            tarih += to_string(dakika);
        }
        else {
            tarih += to_string(dakika);
        }
        tarih += dat1;
        if (saniye < 10) {
            tarih += "0";
            tarih += to_string(saniye);
        }
        else {
            tarih += to_string(saniye);
        }
        tarih += "    ";
        if (gun < 10) {
            tarih += "0";
            tarih += to_string(gun);
        }
        else {
            tarih += to_string(gun);
        }
        tarih += dat2;
        if (ay < 10) {
            tarih += "0";
            tarih += to_string(ay);
        }
        else {
            tarih += to_string(ay);
        }
        tarih += dat2;
        tarih += to_string(yil);// üst kısımla beraber tarih değişkenine alta yazacağımız yazıyı ekleme

        cv::putText(clock, tarih, cv::Point(60, 600), cv::FONT_HERSHEY_COMPLEX_SMALL | cv::FONT_ITALIC, 2, cv::Scalar(255, 0, 0), 2);//ekranın altına tarih ve saat yazan ksıım
        
        cv::line(clock, cv::Point(clock.cols / 2, 280), cv::Point(clock.cols / 2 + 200 * cos((((saniye-1)*6 * M_PI)-270) / 180), 280 + 200 * sin((((saniye) * 6 * M_PI) - 270) / 180)), cv::Scalar(0, 0, 255), 2);
        cv::line(clock, cv::Point(clock.cols / 2, 280), cv::Point(clock.cols / 2 + 170 * cos((((dakika-1 ) * 6 * M_PI) - 270) / 180), 280 + 170 * sin((((dakika ) * 6 * M_PI) - 270) / 180)), cv::Scalar(0, 255, 0), 2);
        cv::line(clock, cv::Point(clock.cols / 2, 280), cv::Point(clock.cols / 2 + 140 * cos(((((saat%12)*5-1) * 6 * M_PI) - 270) / 180), 280 + 140 * sin(((((saat%12)*5) * 6 * M_PI) - 270) / 180)), cv::Scalar(255, 0, 0), 2);
        // burada saat dakika ve saniye için komutlar denklem tam olmadı deneme yanılma ile buldum

        cv::imshow(windowName, clock);//ekrana yansıt komutu
        cclock.copyTo(clock);// yazılar ve şekşiller üst üste binmesin diye her ekrana basma sonrası ekranı temizliyoruz
        if (cv::waitKey(500) == 27) {// esc ile kapatma komutu aynı zamanda 250 ms bekleme ile işlemci yükü azaltma
            break;
        }
        
    }

    return 0;
}
