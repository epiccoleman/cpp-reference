#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>

#define checkCudaErrors(val) check_cuda( (val), #val, __FILE__, __LINE__ )
void check_cuda(cudaError_t result, char const *const func, const char *const file, int const line) {
  if (result) {
    std::cerr << "CUDA error = " << static_cast<unsigned int>(result) << " at " <<
      file << ":" << line << " '" << func << "' \n";
    // Make sure we call CUDA Device Reset before exiting
    cudaDeviceReset();
    exit(99);
  }
}

__global__ void color_pixel(int* pixels, int x_size, int y_size, int max_iterations){
  int i = threadIdx.x + blockIdx.x * blockDim.x;
  int j = threadIdx.y + blockIdx.y * blockDim.y;
  if((i >= x_size) || (j >= y_size)) return;  // make sure we're actually operating on the array

  float c_re = (i - x_size/2.0f)*4.0f/x_size;
  float c_im = (j - y_size/2.0f)*4.0f/x_size;
  float x = 0, y = 0;
  int iteration = 0;
  while (x*x+y*y <= 4 && iteration < max_iterations) {
    float x_new = x*x - y*y + c_re;
    y = 2*x*y + c_im;
    x = x_new;
    iteration++;
  }

  int pixel_index = j * x_size + i;
  if (iteration < max_iterations) {
    pixels[pixel_index] = iteration;
  }
  else {
    pixels[pixel_index] = 0;
  }
}

int main(int argc, char *argv[]){
  int nx = 1000;
  int max = 1000;
  int tx = 8;  // number of thread blocks 
  int ty = 8;  // number of threads in a block

  if(argc > 1){
    nx = atoi(argv[1]);
  }

  int ny = nx;   // for now, grid must be square, so ny = nx

  //allocate color values array
  int num_pixels = nx * ny;
  size_t pixels_size = num_pixels * sizeof(int);

  int *pixels;
  checkCudaErrors(cudaMallocManaged((void **)&pixels, pixels_size));  // allocate shared memory 

  clock_t start, stop;
  start = clock();

  dim3 blocks(nx/tx+1,ny/ty+1); // 1221 blocks 
  dim3 threads(tx,ty);  // total of tx * ty (64) threads in a block
  color_pixel<<<blocks, threads>>>(pixels, nx, ny, max);
  checkCudaErrors(cudaGetLastError());
  checkCudaErrors(cudaDeviceSynchronize());

  stop = clock();
  double timer_seconds = ((double)(stop - start)) / CLOCKS_PER_SEC;
  std::cerr << "took " << timer_seconds << " seconds.\n";

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";
  for(int x = 0; x < nx; x++){
    for(int y = 0; y < ny; y++){
      int pixel_index = x * nx + y;

      int r = 0; // (img[x][y] * 255/100);
      int g = (pixels[pixel_index] * 255/10);
      int b = 0; //(img[x][y] * 255);
      std::cout << r << " " <<  g << " " << b << "\n";
    }
  }
}
