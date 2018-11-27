#ifndef HITABLELIST_H
#define HITABLELIST_H

#include "Hitable.h"

class HitableList: public Hitable {
 public:
  HitableList(){}
  HitableList(Hitable **l, int n);
  virtual bool hit(const Ray& ray, float t_min, float t_max, hit_record& rec) const;
  Hitable **list;
  int list_size;

};

HitableList::HitableList(Hitable **l, int n){
  list = l;
  list_size = n;
}


// more magical untested code
bool HitableList::hit(const Ray& ray, float t_min, float t_max, hit_record& rec) const {
  hit_record temp_rec;
  bool hit_anything = false;
  double closest_so_far = t_max;
  for (int i = 0; i < list_size; i++){
    if (list[i]->hit(ray, t_min, closest_so_far, temp_rec)){
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }
  return hit_anything;
}

#endif //HITABLELIST_H
