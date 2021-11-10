#include "json.h"

void JSON::add(const String key, const uint16_t val) {
  this->pairs.insert(key, val);
}

const String JSON::to_json() const {
  String result = "{";
  for (const auto& pair : this->pairs) {
    result += "\"" + pair.first + "\"";
    result += ":";
    result += String(pair.second);
    result += ",";
  }
  result.remove(result.length() - 1);
  result += "}";
  return result;
}
