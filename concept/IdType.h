
typedef enum { NO_ID, PARENT_ID, ID } IdType;

struct no_id_type
{
    constexpr static IdType value = NO_ID;
};

constexpr IdType no_id_type::value;

struct parent_id_type
{
    constexpr static IdType value = PARENT_ID;
};

constexpr IdType parent_id_type::value;

struct id_type
{
    constexpr static IdType value = ID;
};

constexpr IdType id_type::value;

