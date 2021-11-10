#ifndef JSON_H
#define JSON_H

#include <Arduino.h>
#include <ArxContainer.h>

class JSON {
  public:
    JSON() {};
    void add(const String key, const uint16_t val);
    const String to_json() const;

  private:
    arx::map<String, uint16_t> pairs;
};

#endif
