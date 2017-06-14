#ifndef _C03STATEMACHINEDRAWOBJECT_H
#define _C03STATEMACHINEDRAWOBJECT_H


#include "c03statemachinebase.h"

// implement the state machine C03StateMachineDrawObject
class C03StateMachineDrawObject : public C03StateMachineBase {
  protected:
    class AnyState {
      public:
        virtual ~AnyState();

        // return the upper state
        virtual AnyState * _upper(C03StateMachineDrawObject & stm) = 0;

        // perform the 'do activity'
        virtual void _do(C03StateMachineDrawObject & stm);

        // the current state doesn't manage the event mousePressEvent, give it to the upper state
        virtual void mousePressEvent(C03StateMachineDrawObject & stm);

        virtual void create(C03StateMachineDrawObject & stm);

        // the current state doesn't manage the event mouseMoveEvent, give it to the upper state
        virtual void mouseMoveEvent(C03StateMachineDrawObject & stm);

        // the current state doesn't manage the event keyPressEvent_escape, give it to the upper state
        virtual void keyPressEvent_escape(C03StateMachineDrawObject & stm);

    };
    
    class C03StateMachineDrawObject_State : public AnyState {
      public:
        class wait_State : public AnyState {
          public:
            virtual ~wait_State();

            // to manage the event mousePressEvent
            virtual void mousePressEvent(C03StateMachineDrawObject & stm);

            // returns the state containing the current
            virtual AnyState * _upper(C03StateMachineDrawObject & stm);

        };
        
        class draw_State : public AnyState {
          public:
            virtual ~draw_State();

            // to manage the event mousePressEvent
            virtual void mousePressEvent(C03StateMachineDrawObject & stm);

            // to manage the event mouseMoveEvent
            virtual void mouseMoveEvent(C03StateMachineDrawObject & stm);

            // to manage the event keyPressEvent_escape
            virtual void keyPressEvent_escape(C03StateMachineDrawObject & stm);

            // returns the state containing the current
            virtual AnyState * _upper(C03StateMachineDrawObject & stm);

        };
        
        virtual ~C03StateMachineDrawObject_State();

        // memorize the instance of the state wait, internal
        
        wait_State _wait_state;

        // memorize the instance of the state draw, internal
        
        draw_State _draw_state;

        // to manage the event create
        virtual void create(C03StateMachineDrawObject & stm);

        // perform the 'entry behavior'
        void _doentry(C03StateMachineDrawObject & stm);

        // perform the 'exit behavior'
        void _doexit(C03StateMachineDrawObject & stm);

        // perform the 'do activity'
        virtual void _do(C03StateMachineDrawObject & stm);

        // returns the state containing the current
        virtual AnyState * _upper(C03StateMachineDrawObject & stm);

    };
    
    // memorize the instance of the state C03StateMachineDrawObject, internal
    
    C03StateMachineDrawObject_State _c03statemachinedrawobject_state;


  public:
    C03StateMachineDrawObject();

    virtual ~C03StateMachineDrawObject();

    // the operation you call to signal the event mousePressEvent
    bool mousePressEvent();

  friend class C03StateMachineDrawObject_State::wait_State;
    // the operation you call to signal the event create
    bool create();

    // the operation you call to signal the event mouseMoveEvent
    bool mouseMoveEvent();

    // the operation you call to signal the event keyPressEvent_escape
    bool keyPressEvent_escape();

  friend class C03StateMachineDrawObject_State;
    // to execute the current state 'do activity'
    void doActivity();


  protected:
    // change the current state, internal
    inline void _set_currentState(AnyState & st);

    // execution done, internal
    void _final();

    // contains the current state, internal
    AnyState * _current_state;

  friend class C03StateMachineDrawObject_State::draw_State;

  friend class C03StateMachineDrawObject_State::wait_State;
  friend class C03StateMachineDrawObject_State::draw_State;};
// change the current state, internal
inline void C03StateMachineDrawObject::_set_currentState(C03StateMachineDrawObject::AnyState & st) {
    _current_state = &st;
}

#endif
