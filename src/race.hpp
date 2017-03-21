#ifndef RACE_HPP
#define RACE_HPP

class Race {
  private:
    enum ResourceType { money, research, production };
  public:
    int getResourceRemaining(ResourceType resource);
};

#endif
