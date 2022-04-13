#if !defined(MAX_HEAP)
#define MAX_HEAP
#include "vector"
#include "iostream"

using namespace std;

template <class type_g>
class max_heap
{
    vector<type_g> values;
    int parent(int index){return (index - 1) >> 1;}
    int left(int index){return (index << 1) + 1;}
    int right(int index){return (index << 1) + 2;}
    bool is_leaf(int index) const{return (index > ((values.size()-1)/2)) && (index <= (values.size()-1)) ;}
public:
    max_heap(){}
    bool size() const { return values.size(); }
    bool is_empty() const { return values.size(); }
    type_g get_max() const{ return values[0]; }
    void insert(type_g);
    void shit_up(int);
    void shit_down(int);
    int extract_max();


    // * [IGNORE] tree printer
    void print_tree ();
    void printer (unsigned index, unsigned mlength);
    string do_padding (unsigned index, unsigned mlength);
    // * [IGNORE]

};
#endif // MAX_HEAP

template <class type_g>
void max_heap<type_g>::insert(type_g val){
    values.push_back(val);
    shit_up(values.size()-1);
}

template <class type_g>
void max_heap<type_g>::shit_up(int index){
    if(index == 0) return;

    if (values[parent(index)] < values[index]){

        swap(values[index], values[parent(index)]);
        shit_up(parent(index));
    }
}

template <class type_g>
void max_heap<type_g>::shit_down(int index){
    if(index > values.size() - 1 ) return;
    int idx = index;
    if(left(idx)<= (values.size() - 1) && values[idx]<values[left(idx)]) idx = left(idx);
    if(right(idx)<= (values.size() - 1) && values[idx]<values[right(idx)]) idx = right(idx);
    if(idx != index){
        swap(values[idx],values[index]);
        shit_down(idx);
    }
}

template <class type_g>
int max_heap<type_g>::extract_max(){
    int max = values[0];
    values[0] = values[values.size() - 1];
    values.pop_back();
    shit_down(0);
    return max;
}




// * [IGNORE] tree printer
template <class type_g>
string max_heap<type_g>::do_padding (unsigned index, unsigned mlength){
  string padding;
  if (int((index-1)/2) != 0){
    return (int((index-1)/2) % 2 == 0) ?
    (do_padding(int((index-1)/2),mlength) + string(mlength+4,' ') + " ")  :
    (do_padding(int((index-1)/2),mlength) + string(mlength+3,' ') + " |") ;
  }
  return padding;
}
template <class type_g>
void max_heap<type_g>::printer (unsigned index, unsigned mlength){
  auto _last = values.size() - 1 ;
  auto  _left = 2 * index + 1 ;
  auto  _right = 2 * index + 2 ;
  cout << " " << values[index] << " ";
  if (_left <= _last){
    auto llength = to_string(values[_left]).size();
    cout << "---" << string(mlength - llength,'-');
    printer(_left,mlength);
    if (_right <= _last) {
      auto rlength = to_string(values[_right]).size();
      cout << "\n" << do_padding(_right,mlength) << string(mlength+ 3,' ') << " | ";
      cout << "\n" << do_padding(_right,mlength) << string(mlength+ 3,' ') << " └" <<
      string(mlength - rlength,'-');
      printer(_right,mlength);
    }
  }
}
template <class type_g>
void max_heap<type_g>::print_tree (){
  unsigned mlength = 0;
  for (int & element : values){
    auto clength = to_string(element).size();
    if (clength > mlength) {
      mlength = to_string(element).size();
    }
  }
  cout <<  string(mlength- to_string(values[0]).size(),' ');
  printer(0,mlength);
}
// * [IGNORE]