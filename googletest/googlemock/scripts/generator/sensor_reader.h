/** PerceptIn license **/

#pragma once

#include <memory>
#include <string>
#include <vector>

#include <common/types.h>
#include <items/item.h>
#include <items/sensor_data_item.h>
#include <readers/reader.h>

namespace PI {

// Forward declaration.
class ConfigSet;

/**
 * @brief SensorReader is an Reader to get sensor data Items from a sensor
 */
class SensorReader : public Reader<std::shared_ptr<SensorDataItem> *> {
 public:
  typedef Reader<std::shared_ptr<SensorDataItem> *> ReaderType;
  typedef SensorDataItem OutputItemType;

  /**
   * @brief config for the name of the file from which Items is read
   */
  static const std::string kDirectoryConfig;

  /**
   * @brief constructor.
   * @param configs The set of configs to initialize the SensorReader. Can't be
   * nullptr.
   */
  SensorReader(const std::shared_ptr<const Config> &config);
  /**
   * @brief Move constructor.
   */
  SensorReader(Reader &&reader);
  /**
   * @brief Destructor.
   */
  virtual ~SensorReader();

  // Delete copy constructor and assignment operator
  SensorReader(const SensorReader &other) = delete;
  SensorReader &operator=(const SensorReader &other) = delete;

  // Delete move constructor and assignment operator
  SensorReader(const SensorReader &&other) = delete;
  SensorReader &operator=(const SensorReader &&other) = delete;

  /**
   * @brief Read an sensor data Item
   * @return An Sensor data Item
   */
  Signal Read(std::shared_ptr<SensorDataItem> *item) override;

 private:
  // PIMPL
  class Impl;
  std::shared_ptr<Impl> impl_;
};

}  // namespace PI
