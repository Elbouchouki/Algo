#if !defined(EDGE)
#define EDGE

template <class type_g, class weight_g>
class edge
{
  type_g s, e;
  weight_g w;

public:
  edge(type_g, type_g, weight_g);
  edge(type_g, type_g);
  type_g start() const;
  type_g end() const;
  weight_g weight() const;
  bool is_self() const;
};
template <class type_g, class weight_g>
edge<type_g, weight_g>::edge(type_g start, type_g end) : s(start), e(end), w(1) {}

template <class type_g, class weight_g>
edge<type_g, weight_g>::edge(type_g start, type_g end, weight_g weight) : s(start), e(end), w(weight) {}

template <class type_g, class weight_g>
type_g edge<type_g, weight_g>::start() const
{
  return this->s;
}
template <class type_g, class weight_g>
type_g edge<type_g, weight_g>::end() const
{
  return this->e;
}
template <class type_g, class weight_g>
bool edge<type_g, weight_g>::is_self() const
{
  return this->e == this->s;
}
template <class type_g, class weight_g>
weight_g edge<type_g, weight_g>::weight() const
{
  return this->w;
}
#endif // EDGE
