//Firstly, we have the void functions which contain filters, save functions,
//Then the int main function which contains the menu which runs the program and integrates it with each other, It handles the user interaction, shows the available filters, takes the input, and calls the correct filter function.
//
//name: Omar tharwat Mohamed    id: 20240365    filters done: flip image.
//
//name: Fathi Mostafa                 id:  20242239      filters done: rotate image, gray scale, black and white and the main menu.
//name: Mohamed Hamdy        id: 20240492     filters done: inverted image, resize.
//
//Note: the sections are unknown because we couldn’t register due to the website fall.
//

#include"image_Class.h"
using namespace std ;
#include <iostream>


void TV_Filter(Image &image) {
   
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                if (j % 4 == 0) {

                    image(i, j, k) = image(i, j, k) * 0.1;
                }
            }

        }
    }
}

void To_Warm(Image &image) {


    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {


            unsigned int r = image(i, j, 0) ;
            unsigned int g = image(i, j, 1) ;
            unsigned int b = image(i, j, 2) ;




            image(i, j, 0)=r  ;

            image(i, j, 1)=g ;
            image(i, j, 2)=b*0.65 ;



        }
    }



}
void Purpleinvert(Image &image) {


    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {


            int r = image(i, j, 0) ;
            int g = image(i, j, 1) ;
            int b = image(i, j, 2) ;


            image(i, j, 0)=r ;
            image(i, j, 1)=g*0.45 ;
            image(i, j, 2)=b ;



        }
    }



}

void Blur( Image &image) {


    Image blurred_image(image.width, image.height);

    int blurRadius = 6;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int total_r = 0, total_g = 0, total_b = 0;
            int count = 0;

            for (int x = 0; x <= blurRadius * 2; ++x) {
                for (int y = 0; y <= blurRadius * 2; ++y) {
                    int newX = i + x;
                    int newY = j + y;

                    if (newX >= 0 && newX < image.width && newY >= 0 && newY < image.height) {
                        total_r += image(newX, newY, 0);
                        total_g += image(newX, newY, 1);
                        total_b += image(newX, newY, 2);
                        count++;
                    }
                }
            }

            blurred_image(i, j, 0) = total_r / count;
            blurred_image(i, j, 1) = total_g / count;
            blurred_image(i, j, 2) = total_b / count;
        }
    }


    image=blurred_image;


}
void adjustBrightness(Image &image) {

    std::cout << "Do you want the image darker or lighter? (d/l)\n";
    std::string s;
    std::cin >> s;

    float factor;
    if (s == "d") {
        factor = 0.5;
    }
    else if (s == "l") {
        factor = 1.5;
    }

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                int y = image(i, j, k) * factor;
                if (y > 255) {
                    y = 255;
                }
                else if (y < 0) {
                    y = 0;
                }
                image(i, j, k) = y;
            }
        }
    }
}

void AddFrame(Image &image) {

    cout<< "Do you want a simple with one color or decorated with two colors or captured?"
    << " (s/d/c) ";
    string input;
    cin >> input;

    if (input == "c") {

        double frameW = image.width *0.015;
        double frameH = image.height *0.015;
        for (int i = 1; i <image.width; i++) {
            for (int j = 1; j < image.height; j++) {
                if (

    (i >= frameW * 0.5 && i < frameW) ||


    (i >= image.width - frameW && i < image.width - frameW * 0.5) ||
    (j >= frameH * 0.5 && j < frameH) ||
    (j >= image.height - frameH && j < image.height - frameH * 0.5)
) {
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
}

            }
        }

    }

    else if (input == "s") {
        cout <<"Which color do you want for the frame? (white,black,gold,silver,blue,red,green,yellow,purple)";
        string color;
        cin >> color;
        int red, green, blue;
        double frameW = image.width *0.015;//length of the frame
        double frameH = image.height *0.015;//length of the frame

        if (color == "blue") {
            red =0;    green =0;    blue =255;
        }
        else if (color == "red") {
            red =255;  green =0;    blue =0;
        }
        else if (color == "green") {
            red =0;    green =255;  blue =0;
        }
        else if (color == "yellow") {
            red =255;  green =255;  blue =0;
        }
        else if (color == "purple") {
            red =160;  green =32;   blue =240;
        }
        else if (color == "white") {
            red =255;  green =255;  blue =255;
        }
        else if (color == "black") {
            red =0;    green =0;    blue =0;
        }
        else if (color == "gold") {
            red =255;  green =215;  blue =0;
        }
        else if (color == "silver") {
            red =192;  green =192;  blue =192;
        }


        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                if (i < frameW || i >= image.width - frameW ||
                    j < frameH || j >= image.height - frameH) {
                    image(i, j, 0) = red;
                    image(i, j, 1) = green;
                    image(i, j, 2) = blue;
                }
            }
        }

    }
    else if (input == "d") {
        double frameW = image.width *0.015; //length of the frame
        double frameH = image.height *0.015; // length of the frame
        int red1, green1, blue1, red2, green2, blue2;
        cout<< "which design do you want?\n 1.Royal Red 2.Steel Blue 3. Black Gold 4. White Gold 5. Soft Burgundy 6. Forest Gold";
        string color1;
        cin >> color1;
        switch (color1[0]) {
            case '1':
                red1 = 218; red2 = 139;
            green1 = 165; green2 = 0;
            blue1 = 32; blue2 = 0;
            break;

            case '2':
                red1 = 192; red2 = 0;
            green1 = 192; green2 = 0;
            blue1 = 192; blue2 = 128;
            break;

            case '3':
                red1 = 0; red2 = 255;
            green1 = 0; green2 = 215;
            blue1 = 0; blue2 = 0;
            break;

            case '4':
                red1 = 255; red2 = 255;
            green1 = 255; green2 = 215;
            blue1 = 255; blue2 = 0;
            break;

            case '5':
                red1 = 128; red2 = 245;
            green1 = 0; green2 = 245;
            blue1 = 32; blue2 = 220;
            break;

            case '6':
                red1 = 34; red2 = 218;
            green1 = 70; green2 = 165;
            blue1 = 34; blue2 = 32;
            break;

            default:
                cout << "Invalid choice!\n";
            break;
        }
        for (int i = 1; i < image.width; i++) {
            for (int j = 1; j < image.height; j++) {
                if (i<frameW/2 || i>= image.width- frameW/2 || j<frameH/2 || j>= image.height - frameH/2) {
                    image(i, j, 0) = red1;
                    image(i, j, 1) = green1;
                    image(i, j, 2) = blue1;

                }
                else if (frameW>i || frameH>j || i>= image.width- frameW || j>= image.height - frameH) {
                    image(i, j, 0) = red2;
                    image(i, j, 1) = green2;
                    image(i, j, 2) = blue2;

                }
            }
        }
    }
}
Image To_gray(Image &image) {
    for (int i=0 ;i<image.width;++i){
        for (int j=0;j<image.height;++j) {
            unsigned int avg=0 ;
            for (int k=0;k<image.channels;++k) {
                avg+=image(i,j,k);
            }
            avg = avg /3;
            for (int k=0;k<image.channels;++k) {
                image(i,j,k)=avg;
            }
        }
    }
    return image;
}



void edgeDetection(Image &image) {

    To_gray(image);

    Image copy(image.width, image.height);

    int sobelX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int sobelY[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    for (int i = 1; i < image.width - 1; i++) {
        for (int j = 1; j < image.height - 1; j++) {
            int gx = 0, gy = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int pixel1 = image(i + dx, j + dy, 0);
                    gx += pixel1 * sobelX[dx + 1][dy + 1];
                    gy += pixel1 * sobelY[dx + 1][dy + 1];
                }
            }

            int magnitude = sqrt(gx * gx + gy * gy);
            int threshold = 100;

            if (magnitude > threshold) {
                copy(i, j, 0) = 0;
                copy(i, j, 1) = 0;
                copy(i, j, 2) = 0;
            } else {
                copy(i, j, 0) = 255;
                copy(i, j, 1) = 255;
                copy(i, j, 2) = 255;
            }
        }
    }
image=copy;
}



void to_gray(Image &image) {
    for (int i=0 ;i<image.width;++i){
        for (int j=0;j<image.height;++j) {
            unsigned int avg=0 ;
            for (int k=0;k<image.channels;++k) {
                avg+=image(i,j,k);
            }
            avg = avg /3;
            for (int k=0;k<image.channels;++k) {
                image(i,j,k)=avg;
            }
        }
    }
}
void to_BlackandWhite(Image &image) {
    for (int i=0 ;i<image.width;++i){
        for (int j=0;j<image.height;++j) {
            unsigned int avg=0 ;
            for (int k=0;k<image.channels;++k) {
                avg+=image(i,j,k);

            }
            avg = avg /3;
            unsigned int bw = (avg >= 128) ? 255 : 0;

            for (int k = 0; k < image.channels; ++k) {
                image(i, j, k) = bw;


            }
        }
    }


}
void saving(Image &image) {
    string choice ;
    string filename ;
    cout<<"Do Yo Want To Save It (y,n) : ";
    cin>>choice;
    if (choice == "y") {
        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";
        cin >> filename;
        image.saveImage(filename);
        cout<<"Image saved successfully\n";
    }

}

void rotate90( Image &image) {
    Image temp(image.height, image.width); // After Rotate 90 height==> width && width==>height (* to not to be out of bound)
    for (int i=0; i < image.width; ++i) {
        for (int j=0; j < image.height; ++j) {
            for (int k=0; k < image.channels; ++k) {
                temp(image.height - 1 - j, i, k) = image(i, j, k);
            }
        }
    }
   image = temp ;
}
void rotate180( Image &image) {
    Image temp(image.width, image.height); // Same Height & Width
    for (int i=0; i < image.width; ++i) {
        for (int j=0; j < image.height; ++j) {
            for (int k=0; k < image.channels; ++k) {
                temp(image.width - 1 - i, image.height-1-j, k) = image(i, j, k);
            }
        }
    }
    image = temp ;
}
void rotate270( Image &image) {
    Image temp(image.height, image.width); // After Rotate 90 height==> width && width==>height (* to not to be out of bound)
    for (int i=0; i < image.width; ++i) {
        for (int j=0; j < image.height; ++j) {
            for (int k=0; k < image.channels; ++k) {
                temp( j, image.width-1-i, k) = image(i, j, k);
            }
        }
    }
    image = temp ;
}
void resize (Image &image,int width ,int height) {
    // string filename;
    Image resized_image(width, height);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int org_i=(i * image.width)/width;
            int org_j=(j * image.height)/height;
            for (int k=0 ; k<3 ; k++)  {
                resized_image(i,j,k)=image(org_i,org_j,k);
            }
        }
    }
image = resized_image;
}
void inverted (Image &image) {

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i, j, 0) = 255 - image(i, j, 0);
            image(i, j, 1) = 255 - image(i, j, 1);
            image(i, j, 2) = 255 - image(i, j, 2);
        }
    }

}
// filter 5
void flipImage(Image &image) {

    Image copy(image);

    std::cout << "Do you want it flip vertical or horizontal? (v/h)\n";
    std::string s;
    std::cin >> s;

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                if (s == "h") {
                    image(i, j, k) = copy(image.width - 1 - i, j, k);
                }
                else if (s == "v") {
                    image(i, j, k) = copy(i, image.height - 1 - j, k);
                }
            }
        }
    }


}

Image merge(Image &image1 ,Image &image2) {
    Image temp(image1.width, image1.height);
int image1_widht = image1.width;
int image1_height = image1.height;
int image2_widht = image2.width;
int image2_height = image2.height;
if(image1_widht == image2_widht && image1_height == image2_height) {
    for (int i=0; i < image1.width; ++i) {
        for (int j=0; j < image1.height; ++j) {
            unsigned int avg=0 ;
            unsigned int avg2=0 ;
            for (int k=0; k < image1.channels; ++k) {
                avg=image1(i,j, k)/2;
                avg2=image2(i,j, k)/2;
                temp(i,j,k) = avg + avg2;
            }
        }
    }
    return temp;
}
else {
resize(image2,image1.width,image1.height);
    for (int i=0; i < image1.width; ++i) {
        for (int j=0; j < image1.height; ++j) {
            unsigned int avg=0 ;
            unsigned int avg2=0 ;
            for (int k=0; k < image1.channels; ++k) {
                avg=image1(i,j, k)/2;
                avg2=image2(i,j, k)/2;
                temp(i,j,k) = avg + avg2;
            }
        }
    }
    return temp;

}

}
Image crop(Image &img) {
    int width,height,x,y;
    cout<<"Enter X Start Point";
    cin>>x;
    cout<<"Enter Y Start Point";
    cin>>y;
    cout<<"Enter the Width";
    cin>>width;
    cout<<"Enter the Height";
    cin>>height;
    Image temp(width,height);
    for (int i=0; i < width; ++i) {
        for (int j=0; j <height; ++j) {
            for (int k=0; k < img.channels; ++k) {
                temp(i, j, k) = img(x + i, y + j, k);
            }
        }
    }
return temp;
}
int main(){
    Image img;
    string modify_name ,img_path ;

    cout<<" \n 1:Load a New Image \n 2:Gray \t \t 3:Black and White \n 4:Resize Image \t 5:Invert Image \n "
             "6:Flip Image \t \t 7:Rotate Image \n 8:Merge Image \t \t 9:Crop Image \n 10:Edge Detection \t 11:Add Frame \n 12:Adjust Brightness \t 13:Blur \n 14:Purple invert \t 15:Warm \n 20:Save \t 21:Exit \n  Chose By mentioned name or Number :  ";
    while (true) {
        cin>>modify_name;
        if (modify_name=="1" || modify_name=="Load a New Image") {
            cout<<"Please enter the image path : ";
            cin>>img_path;
            img.loadNewImage(img_path);
            cout<<img_path<<" Loaded \n";
            cout<<" \n 1:Load a New Image \n 2:Gray \t \t 3:Black and White \n 4:Resize Image \t 5:Invert Image \n "
             "6:Flip Image \t \t 7:Rotate Image \n 8:Merge Image \t \t 9:Crop Image \n 10:Edge Detection \t 11:Add Frame \n 12:Adjust Brightness \t 13:Blur \n 14:Purple invert \t 15:Warm \n 20:Save \t 21:Exit \n  ";
            cout<<"Choose the filter you want : ";
        }

        else if (modify_name=="2" || modify_name=="Gray") {
            to_gray(img);
            saving(img);
        }
        else if (modify_name=="3" || modify_name=="Black and White") {
            to_BlackandWhite(img);
            saving(img);
        }
        else if (modify_name=="4" || modify_name=="Resize Image") {
            int width,height;
            cout<<"Pls Enter image width : ";
            cin>>width;
            cout<<"Pls Enter image height : ";
            cin>>height;
            resize(img,width,height);
            saving(img);
        }
        else if (modify_name=="5" || modify_name=="Invert Image") {
            inverted(img);
            saving(img);
        }
        else if (modify_name=="6" || modify_name=="Flip Image") {
            flipImage(img);
            saving(img);
        }
        else if (modify_name=="7" || modify_name=="Rotate") {
            cout<<"1:Rotate 90 \t 2:Rotate 180\n3:Rotate 270 \t \n Choose By Number:";
            string degree;
            cin>>degree;
            if (degree=="1") {
                rotate90(img);
                saving(img);
            }
            else if (degree=="2") {
                rotate180(img);
                saving(img);
            }
            else if (degree=="3") {
                rotate270(img);
                saving(img);
            }
        }
        else if (modify_name=="8" || modify_name=="Merge Image") {
            Image img2 ;
            string image2_path ;
            cout<<"Enter the image2 path : ";
            cin>>image2_path; ;
            img2.loadNewImage(image2_path); ;
            img=merge(img,img2);
            saving(img);
        }
        else if(modify_name=="9" || modify_name=="Crop Image") {
                crop(img);
                saving(img);
        }
        else if(modify_name=="10" || modify_name=="Edge Detection ") {
           edgeDetection(img);
            saving(img);
        }
        else if(modify_name=="11" || modify_name=="Add Frame") {
            AddFrame(img);
            saving(img);
        }
        else if(modify_name=="12" || modify_name=="Adjust Brightness") {
            adjustBrightness(img);
            saving(img);
        }
        else if(modify_name=="13" || modify_name=="Blur") {
            Blur(img);
            saving(img);
        }
        else if(modify_name=="14" || modify_name=="Purple invert") {
            Purpleinvert(img);
            saving(img);
        }
        else if(modify_name=="15" || modify_name=="Warm") {
            To_Warm(img);
            saving(img);
        }
        else if (modify_name=="20" || modify_name=="Save") {
            saving(img);
            cout<<"Image Saved Successfully";
        }
        else if (modify_name=="21" || modify_name=="Exit") {
            break;
        }

    }
    return 0;
}
