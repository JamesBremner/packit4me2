/*
 * File:   Item.h
 * Author: arash
 *
 * Created on June 14, 2012, 1:16 PM
 */

#ifndef ITEM_H
#define	ITEM_H
using namespace std;

struct item_build_instructions;

class Item : public virtual Shape2D
{
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();

    int RotationConstraints();
    int PositionConstraints();
    void set_constraints( int value );
    void setBin( int id )
    {
        myBinProgID = id;
    }
    int getBin() { return myBinProgID; }

    /* Spin around axis
        @param[in] axis ( ignored for 2D, set to 0 )
    */
    virtual void Spin( int axis ) { }

    /** true if spin is allowed according to constraints
    */
    bool IsSpinAllowed( int axis );

    virtual bool FitsInto( bin_t bin ) { return false; }

    /** Claculate spin axis compared to original orientation
    */

    virtual void SpinAxisCalculate() {}

    void Print();

    virtual void encodeAsJSON(stringstream &jsonStr) = 0;
    virtual string getCSV() { return string(""); }


    void Weight( float w )
    {
        myWeight = w;
    }
    float Weight()
    {
        return myWeight;
    }

    void SpinAxis( int axis )
    {
        mySpinAxis = axis;
    }
    int SpinAxis()
    {
        return mySpinAxis;
    }

    int PackSeq()
    {
        return myPackSeq;
    }
    void setPackSeq()
    {
        myPackSeq = nextPackSeq++;
    }
    void ClearPackSeq()
    {
        myPackSeq = 0;
    }

    int Support()
    {
        return mySupport;
    }
    void Support( int s )
    {
        mySupport = s;
    }

    bool getSpinLocation()  { return mySpinLocation; }
    void setSpinLocation( bool s ) { mySpinLocation = s; }
        string getSpin() { return ""; }
    virtual void AddToCutList( cCutList& l ) {}
    virtual void DrawList( std::stringstream& ss) {}


    bool IsPacked()
    {
        return ( myBinProgID != -1 );
    }

    virtual bool IsAboveBelow( std::shared_ptr< Item > other ) { return false; }

static Item* Build(  item_build_instructions& instructions );

protected:
    int     myRotationConstraints;
    int     myPositionConstraints;
    bool    mySpinLocation;
    float   myWeight;
    int     myBinProgID;

private:

    static int nextPackSeq;
    int     myPackSeq;          // packing sequence number
    int     mySpinAxis;         // zero means in original orientation
    int     mySupport;          // % support by items beneath or the ground
};

#endif	/* ITEM_H */

