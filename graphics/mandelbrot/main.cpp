#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

void output_grid(const std::vector<std::vector<int> >& img, std::ostream& os){
  int nx = img.size();
  int ny = img[0].size();
  os << "P3\n" << nx << " " << ny << "\n255\n";
  for(int x = 0; x < nx; x++){
    for(int y = 0; y < ny; y++){
      int r = 0;
      int g = (img[x][y] * 255/24) % 255;
      int b = 0;
      os << r << " " <<  g << " " << b << "\n";
    }
  }
}

void mandelbrot(std::vector<std::vector<int> >& img, int max){
  int nx = img.size();
  int ny = img[0].size();
  int max_iters = 0;
  for (int row = 0; row < ny; row++) {
    for (int col = 0; col < nx; col++) {
      double c_re = (col - nx/2.0)*4.0/nx;  // real part of complex number
      double c_im = (row - ny/2.0)*4.0/nx;  // imaginary part of complex
      double x = 0, y = 0;
      int iteration = 0;
      while (x*x+y*y <= 4 && iteration < max) {
        double x_new = x*x - y*y + c_re;
        y = 2*x*y + c_im;
        x = x_new;
        iteration++;
      }
      if (iteration < max) {
        if (iteration > max_iters) max_iters = iteration;
        img[row][col] = iteration;
      }
      else {
        img[row][col] = 0;
      }
    }
  }
  std::cerr <<  "max iters: " << max_iters << std::endl;
}

int main(int argc, char *argv[]){
  int max_iterations = 1000;
  int nx = (argc > 1) ? atoi(argv[1]) : 1000;
  int ny = nx;

  std::vector<std::vector<int> > img(nx, std::vector<int>(ny));
  mandelbrot(img, max_iterations);
  output_grid(img, std::cout);
}
