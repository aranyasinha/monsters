#ifndef _MONSTER_H
#define _MONSTER_H 0

enum Type{
    NORMAL,
    FIRE,
    WATER,
    ELECTRIC,
    GRASS,
    ICE,
    FIGHT,
    POISON,
    GROUND,
    FLYING,
    PSYCHIC,
    BUG,
    ROCK,
    GHOST,
    DRAGON,
    DARK,
    STEEL
};

float effect(Type atk, Type mon){
    if (atk == NORMAL){
        if ((mon == ROCK) || (mon == STEEL)){
            return(0.5);
        } else if (mon == GHOST){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == FIRE){
        if ((mon == GRASS) || (mon == ICE) || (mon == BUG) || (mon == STEEL)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == WATER) || (mon == ROCK) || (mon == DRAGON)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == WATER){
        if ((mon == FIRE) || (mon == GROUND) || (mon == ROCK)){
            return(2.0);
        } else if ((mon == WATER) || (mon == GRASS) || (mon == DRAGON)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == ELECTRIC){
        if ((mon == WATER) || (mon == FLYING)){
            return(2.0);
        } else if ((mon == ELECTRIC) || (mon == GRASS) || (mon == DRAGON)){
            return(0.5);
        } else if (mon == GROUND){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == GRASS){
        if ((mon == WATER) || (mon == GROUND) || (mon == ROCK)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == GRASS) || (mon == POISON) || (mon == FLYING) || (mon == BUG) || (mon == DRAGON) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == ICE){
        if ((mon == GRASS) || (mon == GROUND) || (mon == FLYING) || (mon == DRAGON)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == WATER) || (mon == ICE) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == FIGHT){
        if ((mon == NORMAL) || (mon == ICE) || (mon == ROCK) || (mon == DARK) || (mon == STEEL)){
            return(2.0);
        } else if ((mon == POISON) || (mon == FLYING) || (mon == PSYCHIC) || (mon == BUG)){
            return(0.5);
        } else if (mon == GHOST){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == POISON){
        if (mon == GRASS){
            return(2.0);
        } else if ((mon == POISON) || (mon == GROUND) || (mon == ROCK) || (mon == GHOST)){
            return(0.5);
        } else if (mon == STEEL){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == GROUND){
        if ((mon == FIRE) || (mon == ELECTRIC) || (mon == POISON) || (mon == ROCK) || (mon == STEEL)){
            return(2.0);
        } else if ((mon == GRASS) || (mon == BUG)){
            return(0.5);
        } else if (mon == FLYING){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == FLYING){
        if ((mon == GRASS) || (mon == FIGHT) || (mon == BUG)){
            return(2.0);
        } else if ((mon == ELECTRIC) || (mon == ROCK) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == PSYCHIC){
        if ((mon == FIGHT) || (mon == POISON)){
            return(2.0);
        } else if ((mon == PSYCHIC) || (mon == STEEL)){
            return(0.5);
        } else if (mon == DARK){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == BUG){
        if ((mon == GRASS) || (mon == PSYCHIC) || (mon == DARK)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == FIGHT) || (mon == POISON) || (mon == FLYING) || (mon == GHOST)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == ROCK){
        if ((mon == FIRE) || (mon == ICE) || (mon == FLYING) || (mon == BUG)){
            return(2.0);
        } else if ((mon == FIGHT) || (mon == GROUND) || (mon == STEEL)){
            return(0.5);
        } else {
            return (1.0);
        }
    } else if (atk == GHOST){
        if ((mon == PSYCHIC) || (mon == GHOST)){
            return(2.0);
        } else if ((mon == DARK) || (mon == STEEL)){
            return(0.5);
        } else if (mon == NORMAL){
            return(0.0);
        } else {
            return(1.0);
        }
    } else if (atk == DRAGON){
        if (mon == DRAGON){
            return(2.0);
        } else if (mon == STEEL){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == DARK){
        if ((mon == PSYCHIC) || (mon == GHOST)){
            return(2.0);
        } else if ((mon == FIGHT) || (mon == DARK) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    } else if (atk == STEEL){
        if ((mon == ICE) || (mon == ROCK)){
            return(2.0);
        } else if ((mon == FIRE) || (mon == WATER) || (mon == ELECTRIC) || (mon == STEEL)){
            return(0.5);
        } else {
            return(1.0);
        }
    }else {
        return (1.0);
    }
}

class Move{
    std::string a_name;
    unsigned int a_power;
    float a_accuracy;
    Type a_t;
public:
	//setters

	void setName(std::string name){
		a_name = name;
	}

	void setPower(unsigned int power){
		a_power = power;
	}

	void setAccuracy(float accuracy){
		a_accuracy = accuracy
	}

	void setType(Type type){
		a_t = type;
	}

	//getters
	std::string getName(){
		return(a_name);
	}

	unsigned int getPower(){
		return(a_power);
	}

	float getAccuracy(){
		return(a_accuracy);
	}

	TYPE getType(){
		return(a_t);
	}

    Move(){
        a_name = "Struggle";
        a_power = 100;
        a_accuracy = 100.00;
        a_t  = NORMAL;
    }

    //~Move();
};

class Monster{
	std::string m_name;
	unsigned int m_base_hp, m_base_attack, m_base_defence, m_base_speed;
    Type m_t[2];
public:
	//setters

	void setName(std::string name){
		m_name = name;
	}

	void setHP(unsigned int hp){
		m_base_hp = hp;
	}

	void setAttack(unsigned int attack){
		m_base_attack = attack;
	}

	void setDefence(unsigned int defence){
		m_base_defence = defence;
	}

	void setSpeed(unsigned int speed){
		m_base_speed = speed;
	}

	void setType(Type type){
		m_t = type;
	}

	//getters

	std::string getName(){
		return(m_name);
	}

	unsigned int getHP(){
		return(m_base_hp);
	}

	unsigned int getAttack(){
		return(m_base_attack);
	}

	unsigned int getDefence(){
		return(m_base_defence);
	}

	unsigned int getSpeed(){
		return(m_base_speed);
	}

	Type getType(){
		return(m_t);
	}

        Monster(){
            m_name = "MissingNo";
            m_base_hp = 33;
            m_base_attack = 136;
            m_base_defence = 6;
            m_base_speed = 29;
        }
	//~Monster();
};

#endif
