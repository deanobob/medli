/*
 * IComponent.h
 *
 *  Created on: 1 Nov 2016
 *      Author: deano
 */

#ifndef MEDLI_CORE_ICOMPONENT_H_
#define MEDLI_CORE_ICOMPONENT_H_

class IComponent
{
  public:
    const unsigned int id;

    IComponent(const unsigned int id);
    virtual ~IComponent();
};

#endif /* MEDLI_CORE_ICOMPONENT_H_ */
