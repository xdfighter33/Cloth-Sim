#include <SFML/Graphics.hpp>
class Simulator {
    public:
    Simulator() = default;
    Simulator(Particle& objects);

    Particle& addObject(sf::Vector2f position, float radius)
    {
        return m_objects.emplace_back(position);
    }

    void setObjectVelocity(Particle& object, sf::Vector2f v)
    {
        object.set_Velo(v,getStepDt());
    }


    void get_distance(Particle& object1, Particle& object2){
    
    const sf::Vector2f object_positions = (object1.pos - object2.pos);

        float distance = sqrt(object_positions);


        
    }
    void updateObject(Particle& object, float dt){
        object.updatePosition(getStepDt());
    }
    const std::vector<Particle>& getObject() const
    {
        return m_objects;
    }
    void addAccerlation(Particle& object, sf::Vector2f Force){

        object.Accerlate(Force);
    }
    

void update()
{
    m_time += m_frame_dt;

    float step_dt = getStepDt();


  for(uint32_t i{m_sub_steps}; i--;)
    {
        //test_centr(step_dt);
        //AttractToCenter(10,Mass,step_dt);
       // applyGravity(step_dt);
        //checkCollsion(step_dt);
        //appplyConstraint(step_dt);
       updateObjects(step_dt);
    }
}


uint32_t return_sub_steps(){

    return m_sub_steps;
}



float return_time(){
    return m_time;
}   


void return_velocity(Particle& object, float dt){

object.getVelocity(dt);
}

float return_m_frame(){
    return m_frame_dt;
}
void setSimulationUpdateRate(uint32_t rate)
{
    m_frame_dt = 1.0f / static_cast<float>(rate);
}

void setSubsStepscount(uint32_t sub_substeps)
{
    m_sub_steps = sub_substeps;
}

float getStepDt() const{
    return m_frame_dt /static_cast<float>(m_sub_steps);
}


uint64_t getObjectCount() const{
    return m_objects.size();
}



 private:
std::vector<Particle> m_objects;

sf::Vector2f m_gravity = {0,1000.0f};
sf::Vector2f Mass = {500,500};
uint32_t m_sub_steps = 1;
float m_time = 0.0f;
float m_frame_dt = 1.0f;



void AttractToCenter(float strength,sf::Vector2f Posi,float dt)
{
//itterate through all objects
//Very Costly on the system
const uint64_t object_count = m_objects.size();
for(uint64_t i{0}; i < object_count; ++i)
{
Particle& object_1 = m_objects[i];

//get Distance from Posi 
float distance_x = Posi.x - object_1.pos.x;
float distance_y = Posi.y - object_1.pos.y; 
float distance = sqrt(distance_x * distance_x + distance_y * distance_y);

float inverse_distance = 1.f / distance;

float normalised_x = inverse_distance * distance_x;
float normalised_y = inverse_distance * distance_y;

float inverse_square_droppoff = inverse_distance * inverse_distance;

///Calulate  Accerlation
sf::Vector2f Accerlation; 

Accerlation.x = normalised_x * strength; 
Accerlation.y = normalised_y * strength; 

//set Accerlation

object_1.AddVelocity(Accerlation,dt);


}
 
}


/*void test_centr(float dt)
{
    sf::Vector2f edge = {1000.0f,1000.0f};

    for (auto& obj : m_objects){
        const int64_t object_count = m_objects.size();
        for(uint64_t i(0); i < object_count; i++ ){
Particle& object_1 = m_objects[1];

// Setting up formula 
float distance_x = edge.x - object_1.getPos().x;
float distance_y = edge.y - object_1.getPos().y;

float distance_x_squared = distance_x * distance_x;
float distance_y_squared = distance_y * distance_y;

float force1 = sqrt(distance_x_squared + distance_y_squared);


float tangent = distance_y / distance_x * 180;


sf::Vector2f force = {force1,force1};





object_1.setVelo(force,dt);






        }
    }
}
*/ 


void applyGravity(Particle& tests,float dt)
{


    for(auto& tests : m_objects){

    tests.Accerlate(m_gravity);
        
    }

}

// Rotation around the boundaries 
void RotateGravity(float dt)
{
    sf::Vector2f Center_point = {500.0f,500.0f};
    float radius; 

}

/*
void checkCollsion(float dt)
{
    const float response_coef = 0.75f;
    const uint64_t object_count = m_objects.size();
    for (uint64_t i{0}; i < object_count; ++i) {
            Particle& object_1 = m_objects[i];
            // Iterate on object involved in new collision pairs
            for (uint64_t k{i + 1}; k < object_count; ++k) {
                Particle&      object_2 = m_objects[k];
                const sf::Vector2f v        = object_1.pos- object_2.pos;
                const float        dist2    = v.x * v.x + v.y * v.y;
                const float        min_dist = object_1.radius + object_2.radius;
                // Check overlapping
                if (dist2 < min_dist * min_dist) {
                    const float        dist  = sqrt(dist2);
                    const sf::Vector2f n     = v / dist;
                    const float mass_ratio_1 = object_1.radius / (object_1.radius + object_2.radius);
                    const float mass_ratio_2 = object_2.radius / (object_1.radius + object_2.radius);
                    const float delta        = 0.5f * response_coef * (dist - min_dist);
                    // Update positions
                    object_1.pos -= n * (mass_ratio_2 * delta);
                    object_2.pos += n * (mass_ratio_1 * delta);
                }
            }
        }
}
*/
void fricition(float dt)
{
const uint64_t object_count = m_objects.size();
}
/*
void appplyConstraint(float dt)
{
    for (auto& obj : m_objects){
        const uint64_t object_count = m_objects.size();

        for (uint64_t i{0}; i < object_count; i++)
        {
            Particle& object = m_objects[i];
            if(object.getPos().y >= 800)
            {
                object.pos.y += -1;
            }
            if(object.getPos().y <= 0)
            {
                object.pos.y += 1;
            }
             if(object.getPos().x >= 950)
            {
                object.pos.x += -1;
            }
             if(object.getPos().x <= 25)
            {
                object.pos.x += 1;
            }
        }
    }
}
*/ 
void updateObjects(float dt)
{
    for (auto&  obj : m_objects)
    {
        obj.updatePosition(dt);
    }
}


};

