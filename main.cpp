
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
            unsigned char bw = (avg >= 128) ? 255 : 0;

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
void reize (Image &image) {
    // string filename;
    int width,height;
    cout<<"Pls Enter image width : ";
    cin>>width;
    cout<<"Pls Enter image height : ";
    cin>>height;
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

int main(){
    Image img;
    string modify_name ,img_path ;

    cout<<" \n 1:Load a New Image \n 2:Gray \t \t 3:Black and White \n 4:Resize Image \t 5:Invert Image \n "
             "6:Flip Image \t \t 7:Rotate Image \n 8:Save \t 9:Exit \n Chose By mentioned name or Number :  ";
    while (true) {
        cin>>modify_name;
        if (modify_name=="1" || modify_name=="Load a New Image") {
            cout<<"Please enter the image path : ";
            cin>>img_path;
            img.loadNewImage(img_path);
            cout<<img_path<<" Loaded \n";
            cout<<" \n 1:Load a New Image \n 2:Gray \t \t 3:Black and White \n 4:Resize Image \t 5:Invert Image \n "
             "6:Flip Image \t \t 7:Rotate Image \n 8:Save \t 9:Exit \n  ";
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
            reize(img);
            saving(img);
        }
        else if (modify_name=="5" || modify_name=="Invert Image") {
            inverted(img);
            saving(img);
        }
        else if (modify_name=="6" || modify_name=="Invert Image") {
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
        else if (modify_name=="8" || modify_name=="Save") {
            saving(img);
            cout<<"Image Saved Successfully";
        }
        else if (modify_name=="9" || modify_name=="Exit") {
            break;
        }

    }
    return 0;
}
