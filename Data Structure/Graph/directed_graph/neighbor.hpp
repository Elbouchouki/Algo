#if !defined(NEIGHBOR)
#define NEIGHBOR

template <class type_g, class weight_g>
class neighbor
{
public:
  type_g key;
  weight_g weight;
  neighbor(type_g, weight_g);
};

template <class type_g, class weight_g>
neighbor<type_g, weight_g>::neighbor(type_g k, weight_g w) : key(k), weight(w) {}

#endif // NEIGHBOR