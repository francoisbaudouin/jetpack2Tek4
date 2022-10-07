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
    virtual ~IScene() = default;
    virtual void OnCreate() = 0;
    virtual void OnDestroy() = 0;
    virtual void OnActivate() = 0;
    virtual void OnDeactivate() = 0;
    virtual void ProcessInput() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
};

#endif /* !ISCENE_HPP_ */
