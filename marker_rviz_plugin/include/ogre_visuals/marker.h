/*
 * Copyright (c) 2016, Lukas Pfeifhofer <lukas.pfeifhofer@devlabs.pro>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MARKER_RVIZ_PLUGIN_MARKER_H
#define MARKER_RVIZ_PLUGIN_MARKER_H

#include <string>
#include "rviz/ogre_helpers/object.h"
#include "rviz/ogre_helpers/axes.h"
#include "rviz/ogre_helpers/movable_text.h"

namespace Ogre {
    class SceneManager;

    class SceneNode;

    class Entity;
}

namespace marker_rviz_plugin {

    class MarkerResources {
    public:
        MarkerResources();

        ~MarkerResources();
    };

    class Marker : public rviz::Object {
    public:

        Marker(Ogre::SceneManager *scene_manager, Ogre::SceneNode *parent_node = 0, int id = -1);

        virtual ~Marker();

        void setShowAxes(bool showAxes);

        void setShowMarker(bool showMarker);

        void setShowLabel(bool showLabel);
	
        void setColorLabel(Ogre::ColourValue color);

        virtual void setColor(float r, float g, float b, float a);

        virtual void setOrientation(const Ogre::Quaternion &orientation);

        virtual void setPosition(const Ogre::Vector3 &position);

        virtual void setScale(const Ogre::Vector3 &scale);

        virtual const Ogre::Vector3 &getPosition();

        virtual const Ogre::Quaternion &getOrientation();

        void setUserData(const Ogre::Any &data);

    protected:
        static MarkerResources static_resources_; // load static resources once for this class

        Ogre::SceneNode *scene_node_;
        Ogre::SceneNode *markerNode_;

        Ogre::Entity *markerEntity_;
        rviz::Axes *axes_;
        rviz::MovableText *text_;
        Ogre::SceneNode *text_node_;

    };

}


#endif //MARKER_RVIZ_PLUGIN_MARKER_H
