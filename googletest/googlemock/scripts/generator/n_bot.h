/** PerceptIn license **/

#pragma once

#include <string>
#include "bot.h"
#include "circle_buffer.h"
#include "n_bot_comm.h"
#include "serial.h"

namespace PIRoBot {

class NBot : public Bot {
 public:
  NBot();
  bool InitBot(std::string serialName);
  void SetLinearAndAugularVelocity(double _linearV, double _angularV);
  void SetDeltaDistAndAngle(float _moveDist, float _rotAngle);
  void StopBot();
  void Finish();
  void RunOnce();

  double gyrZ;
  std::string timestampStr;

  std::mutex mutexNewBotDataSensor;
  NBotDataSensor botDataSensor;
  bool bNewBotDataSensor;

  uint64_t recvTimestamp;

 private:
  void WriteCmd(NFuncCode fc, unsigned char* cmdBuf, int32_t cmdLen);
  void ProcessPackageData(const unsigned char* dataBuf, int32_t dataLen);
  bool AnalysisPackage(CircleBuffer* circleBuf, unsigned char* dataBuf,
                       int32_t* dataLen);
  void PackageData(NFuncCode fc, unsigned char* data, int32_t len,
                   unsigned char* sendBuf, int32_t* sendLen);
  Serial serial;
  NBotDataSensor botDataSensorInternal;
  bool bNewBotDataSensorInternal;
  uint64_t recvTimestampInternal;
  CircleBuffer circleBuf;
};
}
