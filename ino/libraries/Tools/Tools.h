#ifndef Tools_h
#define Tools_h

// #include "Arduino.h"

class Tools {
  public:
    void dht_out(String label, float temp, float humidity);
    void out(String label, float val, String prefix, String postfix);
};

#endif
