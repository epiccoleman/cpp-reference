#include <iostream>
#include <cmath>

int main(){
  int nx = 20;
  int ny = 20;
  int max = 1000;

  int img[nx][ny];

for (int row = 0; row < ny; row++) {
  for (int col = 0; col < nx; col++) {
    double c_re = (col - nx/2.0)*4.0/nx;
    double c_im = (row - ny/2.0)*4.0/nx;
    double x = 0, y = 0;
    int iteration = 0;
    while (x*x+y*y <= 4 && iteration < max) {
      double x_new = x*x - y*y + c_re;
      y = 2*x*y + c_im;
      x = x_new;
      iteration++;
    }
    if (iteration < max) {
      img[row][col] = 0;
    }
    else {
      img[row][col] = 1;
    }
  }
 }

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";
  for(int x = 0; x < nx; x++){
    for(int y = 0; y < ny; y++){
      int r = (img[x][y] * 255);
      int g = (img[x][y] * 255);
      int b = (img[x][y] * 255);
      std::cout << r << " " <<  g << " " << b << "\n";
    }
  }
}
