
#include "C03StateMachineDrawObject.h"

C03StateMachineDrawObject::AnyState::~AnyState(){
}

// perform the 'do activity'
void C03StateMachineDrawObject::AnyState::_do(C03StateMachineDrawObject & stm) {
}

// the current state doesn't manage the event mousePressEvent, give it to the upper state
void C03StateMachineDrawObject::AnyState::mousePressEvent(C03StateMachineDrawObject & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->mousePressEvent(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition mousePressEvent not expected");
#endif
}

void C03StateMachineDrawObject::AnyState::create(C03StateMachineDrawObject & stm) {
}

// the current state doesn't manage the event mouseMoveEvent, give it to the upper state
void C03StateMachineDrawObject::AnyState::mouseMoveEvent(C03StateMachineDrawObject & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->mouseMoveEvent(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition mouseMoveEvent not expected");
#endif
}

// the current state doesn't manage the event keyPressEvent_escape, give it to the upper state
void C03StateMachineDrawObject::AnyState::keyPressEvent_escape(C03StateMachineDrawObject & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->keyPressEvent_escape(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition keyPressEvent_escape not expected");
#endif
}

C03StateMachineDrawObject::C03StateMachineDrawObject_State::wait_State::~wait_State(){
}

// to manage the event mousePressEvent
void C03StateMachineDrawObject::C03StateMachineDrawObject_State::wait_State::mousePressEvent(C03StateMachineDrawObject & stm) {
    {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : execute activity of transition <transition>");
#endif
/*
  createNewNode()
  createNewNode()
  createNewLink()
*/
      stm._set_currentState(stm._c03statemachinedrawobject_state._draw_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .C03StateMachineDrawObject.draw");
#endif
    }
}

// returns the state containing the current
C03StateMachineDrawObject::AnyState * C03StateMachineDrawObject::C03StateMachineDrawObject_State::wait_State::_upper(C03StateMachineDrawObject & stm) {
    return &stm._c03statemachinedrawobject_state;
}

C03StateMachineDrawObject::C03StateMachineDrawObject_State::draw_State::~draw_State(){
}

// to manage the event mousePressEvent
void C03StateMachineDrawObject::C03StateMachineDrawObject_State::draw_State::mousePressEvent(C03StateMachineDrawObject & stm) {
    {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : execute activity of transition <transition>");
#endif
  /*
 createNewNode()
  createNewLink()
  */
    }
}

// to manage the event mouseMoveEvent
void C03StateMachineDrawObject::C03StateMachineDrawObject_State::draw_State::mouseMoveEvent(C03StateMachineDrawObject & stm) {
    {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : execute activity of transition <transition>");
#endif
  /*
   * moveCurrentNode()
  updateLink()
  */
    }
}

// to manage the event keyPressEvent_escape
void C03StateMachineDrawObject::C03StateMachineDrawObject_State::draw_State::keyPressEvent_escape(C03StateMachineDrawObject & stm) {
    {
      stm._set_currentState(stm._c03statemachinedrawobject_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .C03StateMachineDrawObject");
#endif
      if (nbNode>2) {
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : execute activity of transition <transition>");
#endif
  //finalisePolygon()

          stm._set_currentState(stm._c03statemachinedrawobject_state._wait_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .C03StateMachineDrawObject.wait");
#endif
      }
      else if (nbNode<3) {
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : execute activity of transition <transition>");
#endif
  deleteCurrentPolygon()      stm._set_currentState(stm._c03statemachinedrawobject_state._wait_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .C03StateMachineDrawObject.wait");
#endif
      }
    }
}

// returns the state containing the current
C03StateMachineDrawObject::AnyState * C03StateMachineDrawObject::C03StateMachineDrawObject_State::draw_State::_upper(C03StateMachineDrawObject & stm) {
    return &stm._c03statemachinedrawobject_state;
}

C03StateMachineDrawObject::C03StateMachineDrawObject_State::~C03StateMachineDrawObject_State(){
}

// to manage the event create
void C03StateMachineDrawObject::C03StateMachineDrawObject_State::create(C03StateMachineDrawObject & stm) {
    _doentry(stm);
    _do(stm);
    {
      stm._set_currentState(stm._c03statemachinedrawobject_state._wait_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .C03StateMachineDrawObject.wait");
#endif
    }
}

// perform the 'entry behavior'
void C03StateMachineDrawObject::C03StateMachineDrawObject_State::_doentry(C03StateMachineDrawObject & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .C03StateMachineDrawObject");
#endif
  //entry behavior
}

// perform the 'exit behavior'
void C03StateMachineDrawObject::C03StateMachineDrawObject_State::_doexit(C03StateMachineDrawObject & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .C03StateMachineDrawObject");
#endif
  exit behavior
}

// perform the 'do activity'
void C03StateMachineDrawObject::C03StateMachineDrawObject_State::_do(C03StateMachineDrawObject & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute do behavior of .C03StateMachineDrawObject");
#endif
  //do behavior
}

// returns the state containing the current
C03StateMachineDrawObject::AnyState * C03StateMachineDrawObject::C03StateMachineDrawObject_State::_upper(C03StateMachineDrawObject & stm) {
    return 0;
}

C03StateMachineDrawObject::C03StateMachineDrawObject(){
    _current_state = 0;
}

C03StateMachineDrawObject::~C03StateMachineDrawObject(){
}

// the operation you call to signal the event mousePressEvent
bool C03StateMachineDrawObject::mousePressEvent() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger mousePressEvent");
#endif
      _current_state->mousePressEvent(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event create
bool C03StateMachineDrawObject::create() {
  if (_current_state == 0)
  (_current_state = &(*this)._c03statemachinedrawobject_state)->create(*this);
  return (_current_state != 0);
}

// the operation you call to signal the event mouseMoveEvent
bool C03StateMachineDrawObject::mouseMoveEvent() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger mouseMoveEvent");
#endif
      _current_state->mouseMoveEvent(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event keyPressEvent_escape
bool C03StateMachineDrawObject::keyPressEvent_escape() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger keyPressEvent_escape");
#endif
      _current_state->keyPressEvent_escape(*this);
    }
    return (_current_state != 0);
}

// to execute the current state 'do activity'
void C03StateMachineDrawObject::doActivity() {
    _current_state->_do(*this);
}

// execution done, internal
void C03StateMachineDrawObject::_final() {
    _current_state = 0;
#ifdef VERBOSE_STATE_MACHINE
    puts("DEBUG : final state reached");
#endif
}

