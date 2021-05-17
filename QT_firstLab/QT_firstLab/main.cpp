#include "Filter.h"


int main(int argc, char* argv[])
{
    std::string s;
    QImage img;

    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-p") && (i + 1 < argc))
            s = argv[i + 1];
    }

    img.load(QString(s.c_str()));
    img.save("C:/Images/Source.png");

    char size[80];
    std::ifstream ifs("KernelM.txt");
    ifs.getline(size, 3, '\n');
    int sizei = std::atoi(size);
    Kernel MatKernel(sizei);
    std::unique_ptr<float[]> tmp = std::make_unique<float[]>(sizei * sizei);

    for (int i = 0; i < sizei * sizei; i++)
    {
        ifs.getline(size, 3, '\n');
        tmp[i] = std::atoi(size);
    }

    MatKernel.SetKernel(tmp.get(), sizei / 2);

    InvertFilter invert;
    invert.process(img).save("C:/Images/Invert.png");

    BlurFilter blur;
    blur.process(img).save("C:/Imagess/Blur.png");

    GaussianFilter gauss;
    gauss.process(img).save("C:/Images/Gauss.png");

    GrayScaleFilter gray;
    gray.process(img).save("C:/Images/Gray.png");

    Sepia sep;
    sep.process(img).save("C:/Images/Sep.png");

    BrightUp bright;
    bright.process(img).save("C:/Images/Bright.png");

    SharpnessUp sharpness;
    sharpness.process(img).save("C:/ImagesSharpnessUp.png");

    GreyWorldFilter gworld;
    gworld.process(img).save("C:/Images/GreyWorld.png");

    Transfer trasf;
    trasf.process(img).save("C:/ImagesTransfer.png");

    Glass glass;
    glass.process(img).save("C:/Images/Glass.png");

    Sharpness sharp;
    sharp.process(img).save("C:/Images/Sharpness.png");

    MotionBlur motblur;
    motblur.process(img).save("C:/Imagess/MotionBlur.png");
   
    Dilation dil(MatKernel);
    dil.process(img).save("C:/Images/Dilation.png");
   

    Erosion eros(MatKernel);
    eros.process(img).save("C:/Images/Erosion.png");

    Opening op(MatKernel);
    op.process(img).save("C:/Images/Opening.png");

    
    Closing cl(MatKernel);
    cl.process(img).save("C:/Images/Closing.png");

    LinealStretching lin(img);
    lin.process(img).save("C:/Images/LinealStretching.png");

    Grad grad(MatKernel);
    grad.process(img).save("C:/Images/Gradient.png");

    Median med;
    med.process(img).save("C:/Images/Median.png");

    SobelFilterX sobelx;
    sobelx.process(img).save("C:/Images/SobelX.png");

    SobelFilterY sobelY;
    sobelY.process(img).save("C:/Images/SobelY.png");
    

    return 0;
}
