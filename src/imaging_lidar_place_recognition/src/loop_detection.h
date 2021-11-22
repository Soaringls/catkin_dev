#pragma once
#include "keyframe.h"
#include "parameters.h"

class LoopDetector {
 public:
  DBoW3::Database db;
  DBoW3::Vocabulary* voc;

  map<int, cv::Mat> image_pool;

  list<KeyFrame*> keyframe_list;

  LoopDetector();
  void loadVocabulary(std::string voc_path);

  void addKeyFrame(KeyFrame* cur_kf, bool flag_detect_loop);
  void addKeyFrameIntoVoc(KeyFrame* keyframe);
  KeyFrame* getKeyFrame(int index);

  int detectLoop(KeyFrame* keyframe, int frame_index);
};
