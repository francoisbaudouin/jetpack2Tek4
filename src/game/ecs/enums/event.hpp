/*
** EPITECH PROJECT, 2022
** jetpack2Tek4
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

namespace ecs
{
    struct Device {
        enum MouseKey {
            UNKNOWN_MOUSE_KEY,
            LEFT,
            RIGHT,
            WHEEL,
        };
        enum KeyBoardKey {
            UNKNOWN_KEYBOARD_KEY,
            A = 0,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            Num0,
            Num1,
            Num2,
            Num3,
            Num4,
            Num5,
            Num6,
            Num7,
            Num8,
            Num9,
            Escape,
            LControl,
            LShift,
            LAlt,
            LSystem,
            RControl,
            RShift,
            RAlt,
            RSystem,
            Menu,
            LBracket,
            RBracket,
            Semicolon,
            Comma,
            Period,
            Quote,
            Slash,
            Backslash,
            Tilde,
            Equal,
            Hyphen,
            Space,
            Enter,
            Backspace,
            Tab,
            PageUp,
            PageDown,
            End,
            Home,
            Insert,
            Delete,
            Add,
            Subtract,
            Multiply,
            Divide,
            Left,
            Right,
            Up,
            Down,
            Numpad0,
            Numpad1,
            Numpad2,
            Numpad3,
            Numpad4,
            Numpad5,
            Numpad6,
            Numpad7,
            Numpad8,
            Numpad9,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            Pause,
            KeyCount,
            Dash = Hyphen,
            BackSpace = Backspace,
            BackSlash = Backslash,
            SemiColon = Semicolon,
            Return = Enter
        };
    };

    enum EventType {
        UNKNOWN_TYPE,
        PRESSED,
        REALEASED,
    };

    struct RTypeEvent {
        Device::KeyBoardKey keyboardKey;
        Device::MouseKey mouseKey;

        EventType eventType;
        // struct MouseEvent {
        //     struct MousePressed {
        //         Mouse::Key code;
        //     };
        //     struct MouseRealeased {
        //         Mouse::Key code;
        //     };
        // };
        // struct KeyboardEvent {
        //     struct KeyboardPressed {
        //         Keyboard::Key code;
        //     };
        //     struct KeyboardRealeased {
        //         Keyboard::Key code;
        //     };
        // };
    };
} // namespace ecs

#endif /* !EVENT_HPP_ */
