#ifndef ANDROID_DVR_BUFFER_HUB_BINDER_H
#define ANDROID_DVR_BUFFER_HUB_BINDER_H

#include <binder/BinderService.h>

#include "android/dvr/BnBufferHub.h"

namespace android {
namespace dvr {

class BufferHubBinderService : public BinderService<BufferHubBinderService>, public BnBufferHub {
 public:
  static status_t start();
  static const char* getServiceName() { return "bufferhubd"; }
  // Dump bufferhub related information to given fd (usually stdout)
  // usage: adb shell dumpsys bufferhubd
  virtual status_t dump(int fd, const Vector<String16> &args) override;
};

}  // namespace dvr
}  // namespace android

#endif // ANDROID_DVR_BUFFER_HUB_BINDER_H