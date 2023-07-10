class Serializable
{

public:
    Serializable(){};
  virtual  ~Serializable(){};
  virtual void serialize(std::istream& s) = 0;
  virtual void deserialize(std::ostream& s) = 0;
};

