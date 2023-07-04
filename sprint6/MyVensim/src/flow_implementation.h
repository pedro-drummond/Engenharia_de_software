#ifndef FLOW_H
#define FLOW_H

#include "flow.h"
#include <iostream>
#include "handleBodySemDebug.h"

using namespace std;

/// @brief The BaseFlow class represents a flow between two systems. 
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// BaseFlow *flow1 = new BaseFlow(system1, system2);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///@see Exp
///@see Logistic
class BaseFlow : public Body{

    protected:
        /// @brief This attribute represents the origin of the flow

        System *origin;
        /// @brief This attribute represents the destination of the flow

        System *destination;
    public:
        // getter and setter
        virtual System* getSource() const;
        virtual System* getTarget() const;
        virtual void setSource(System *sOrigin);
        virtual void setTarget(System *sDestination);

        // functions
        virtual double run();
        virtual void clearFlow();

};

class FlowHandle : public Flow, public Handle<BaseFlow> {
    public:
        FlowHandle(System* source, System* target){
            pImpl_->setSource(source);
            pImpl_->setTarget(target);
        }

        System *getSource() const{
            return pImpl_->getSource();
        }

        System *getTarget() const{
            return pImpl_->getTarget();
        }

        void setSource(System* ssource){
            pImpl_->setSource(ssource);
        }

        void setTarget(System* starget){
            pImpl_->setTarget(starget);
        }

        double execute(){
            return pImpl_->run();
        }

        void clearFlow(){
            pImpl_->clearFlow();
        }
};

#endif // FLOW_H
