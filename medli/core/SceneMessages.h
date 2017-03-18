/*
 * SceneMessages.h
 *
 *  Created on: 26 Feb 2017
 *      Author: deano
 */

#ifndef MEDLI_CORE_SCENEMESSAGES_H_
#define MEDLI_CORE_SCENEMESSAGES_H_

#include <string>
#include "Message.h"

namespace MessageId
{
  static const std::string SCENE_STATE = "SCENE_STATE";
}

class SceneMessageState :
    public Message
{
  public:
    const std::string sceneId;
    const bool enabled;
    const bool visible;

    SceneMessageState(const std::string sceneId, const bool enabled, const bool visible) :
        Message(MessageId::SCENE_STATE), sceneId(sceneId), enabled(enabled), visible(visible)
    {

    }

    virtual ~SceneMessageState()
    {

    }
};

#endif /* MEDLI_CORE_SCENEMESSAGES_H_ */
