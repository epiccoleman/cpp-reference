#include <iostream>
#include <cmath>
#include <vector>

int main(int argc, char *argv[]){
  int nx = 1000;
  int max = 1000;

  if(argc > 1){
    nx = atoi(argv[1]);
  }

  int ny = nx;

  std::vector<std::vector<int> > img(nx, std::vector<int>(ny));

  int max_iters = 0;
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
      if (iteration > max_iters) max_iters = iteration;
      img[row][col] = iteration;
    }
    else {
      img[row][col] = 0;
    }
  }
 }
 std::cerr <<  "max iters: " << max_iters << std::endl;

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";
  for(int x = 0; x < nx; x++){
    for(int y = 0; y < ny; y++){
      int r = 0; // (img[x][y] * 255/100);
      int g = (img[x][y] * 255/10);
      int b = 0; //(img[x][y] * 255);
      std::cout << r << " " <<  g << " " << b << "\n";
    }
  }
}
