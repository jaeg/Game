#pragma once
class Referenced
{
private:
	int referenceCount;
public:
	Referenced();
	virtual ~Referenced() {};
	void Add(); //Increments the referenceCount
	void Drop(); //Drop decrements the referenceCount and if it 0 deletes the object.
};