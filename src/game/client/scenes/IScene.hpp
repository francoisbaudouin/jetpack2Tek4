/*
** EPITECH PROJECT, 2022
** RTypeMirror
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

class IScene {
    public:
        virtual void OnCreate() = 0;
        virtual void OnDestroy() = 0;
        virtual void OnActivate() {};
        virtual void OnDeactivate() {};
        virtual void ProcessInput() {};
        virtual void Update() {};
        virtual void Draw() {};
};

#endif /* !ISCENE_HPP_ */
