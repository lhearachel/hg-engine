#ifndef POKEMON_H
#define POKEMON_H

#include "config.h"
//#include "save.h"
#include "types.h"

#define POKEMON_GENDER_MALE 0
#define POKEMON_GENDER_FEMALE 1
#define POKEMON_GENDER_UNKNOWN 2

#define MONS_MALE       (0)
#define MONS_FEMALE     (254)
#define MONS_UNKNOWN    (255)

// MON_DATA_RESERVED_113 fields
#define DUMMY_P2_1_HIDDEN_ABILITY_MASK (0x01)
#define DUMMY_P2_1_HAS_HIT_NECESSARY_CRITICAL_HITS (0x02)


#define SET_MON_HIDDEN_ABILITY_BIT(mon) { \
    u16 tempvarassumeunused = GetMonData(mon, MON_DATA_RESERVED_113, 0); \
    tempvarassumeunused |= DUMMY_P2_1_HIDDEN_ABILITY_MASK; \
    SetMonData(mon, MON_DATA_RESERVED_113, (u8 *)&tempvarassumeunused); \
}
#define SET_BOX_MON_HIDDEN_ABILITY_BIT(boxmon) { \
    u16 tempvarassumeunused = GetBoxMonData(boxmon, MON_DATA_RESERVED_113, 0); \
    tempvarassumeunused |= DUMMY_P2_1_HIDDEN_ABILITY_MASK; \
    SetBoxMonData(boxmon, MON_DATA_RESERVED_113, (u8 *)&tempvarassumeunused); \
}


#define SET_MON_CRITICAL_HIT_EVOLUTION_BIT(mon) { \
    u16 tempvarassumeunused = GetMonData(mon, MON_DATA_RESERVED_113, 0); \
    tempvarassumeunused |= DUMMY_P2_1_HAS_HIT_NECESSARY_CRITICAL_HITS; \
    SetMonData(mon, MON_DATA_RESERVED_113, (u8 *)&tempvarassumeunused); \
}
#define SET_BOX_MON_CRITICAL_HIT_EVOLUTION_BIT(boxmon) { \
    u16 tempvarassumeunused = GetBoxMonData(boxmon, MON_DATA_RESERVED_113, 0); \
    tempvarassumeunused |= DUMMY_P2_1_HAS_HIT_NECESSARY_CRITICAL_HITS; \
    SetBoxMonData(boxmon, MON_DATA_RESERVED_113, (u8 *)&tempvarassumeunused); \
}


#define POW_RND (32)


// personal narc fields
enum
{
    PERSONAL_BASE_HP = 0,
    PERSONAL_BASE_ATTACK,
    PERSONAL_BASE_DEFENSE,
    PERSONAL_BASE_SPEED,
    PERSONAL_BASE_SP_ATTACK,
    PERSONAL_BASE_SP_DEFENSE,
    PERSONAL_TYPE_1,
    PERSONAL_TYPE_2,
    PERSONAL_CATCH_RATE,
    PERSONAL_EXP_YIELD,
    PERSONAL_EV_YIELD_HP,
    PERSONAL_EV_YIELD_ATTACK,
    PERSONAL_EV_YIELD_DEFENSE,
    PERSONAL_EV_YIELD_SPEED,
    PERSONAL_EV_YIELD_SP_ATTACK,
    PERSONAL_EV_YIELD_SP_DEFENSE,
    PERSONAL_ITEM_1,
    PERSONAL_ITEM_2,
    PERSONAL_GENDER_RATIO,
    PERSONAL_EGG_CYCLES,
    PERSONAL_BASE_FRIENDSHIP,
    PERSONAL_EXP_GROUP,
    PERSONAL_EGG_GROUP_1,
    PERSONAL_EGG_GROUP_2,
    PERSONAL_ABILITY_1,
    PERSONAL_ABILITY_2,
    PERSONAL_RUN_CHANCE,
    PERSONAL_BODY_COLOR,
    PERSONAL_FLIP,
    PERSONAL_TM_ARRAY_1,
    PERSONAL_TM_ARRAY_2,
    PERSONAL_TM_ARRAY_3,
    PERSONAL_TM_ARRAY_4,
};

#define MAX_IVS (31)

#define RND_NO_SET  (0)
#define RND_SET (1)

#define ID_NO_SET   (0)
#define ID_SET  (1)
#define ID_NO_SHINY (2)
#define NO_MOVES_SET    (0xffff)
#define SAME_MOVES_SET  (0xfffe)

typedef struct SEAL {
    u8 kind;           // ID of the seal
    u8 x;              // X coordinate on the capsule
    u8 y;              // Y coordinate on the capsule
} SEAL;

/*
 * Capsule that you put on your ball
 */
typedef struct CAPSULE {
    SEAL seals[8];  // The seals on the capsule
} CAPSULE;

typedef struct {
    /* 0x00 */ u16 species;
    /* 0x02 */ u16 heldItem;
    /* 0x04 */ u32 otID; // low 16: visible; high 16: secret
    /* 0x08 */ u32 exp;
    /* 0x0C */ u8 friendship;
    /* 0x0D */ u8 ability;
    /* 0x0E */ u8 markings; // circle, triangle, square, heart, star, diamond
    /* 0x0F */ u8 originLanguage;
    /* 0x10 */ u8 hpEV;
    /* 0x11 */ u8 atkEV;
    /* 0x12 */ u8 defEV;
    /* 0x13 */ u8 spdEV;
    /* 0x14 */ u8 spatkEV;
    /* 0x15 */ u8 spdefEV;
    /* 0x16 */ u8 coolStat;
    /* 0x17 */ u8 beautyStat;
    /* 0x18 */ u8 cuteStat;
    /* 0x19 */ u8 smartStat;
    /* 0x1A */ u8 toughStat;
    /* 0x1B */ u8 sheen;
    // TODO: Finish SinnohRibbonSet1
    /* 0x1C */ u32 sinnohRibbons;
//    u8 sinnohChampRibbon:1, abilityRibbon:1;
//    u8 field_0x1d;
//    u8 gorgeousRoyalRibbon:1, footprintRibbon:1;
//    u8 field_0x1f;
} PokemonDataBlockA;

typedef struct {
    /* 0x00 */ u16 moves[4];
    /* 0x08 */ u8 movePP[4];
    /* 0x0C */ u8 movePpUps[4];
    /* 0x10 */ u32 hpIV:5, atkIV:5, defIV:5, spdIV:5, spatkIV:5, spdefIV:5, isEgg:1, isNicknamed:1;
    // TODO: Finish HoennRibbonSet
    /* 0x14 */ u32 ribbonFlags; // cool, ...
    /* 0x18 */ u8 fatefulEncounter:1, gender:2, alternateForm:5;
    /* 0x19 */ u8 HGSS_shinyLeaves:6;
    /* 0x19 */ u8 unk_19_6:2;
    /* 0x1A */ u16 Unused;
    /* 0x1C */ u16 Platinum_EggLocation;
    /* 0x1E */ u16 Platinum_MetLocation;
} PokemonDataBlockB;

typedef struct {
    /* 0x00 */ u16 nickname[11];
    /* 0x16 */ u8 Unused;
    /* 0x17 */ u8 originGame;
    // TODO: Finish SinnohRibbonSet2
    /* 0x18 */ u64 sinnohRibbons2; // cool, ...
} PokemonDataBlockC;

typedef struct {
    /* 0x00 */ u16 otTrainerName[8];
    /* 0x10 */ u8 dateEggReceived[3];
    /* 0x13 */ u8 dateMet[3];
    /* 0x16 */ u16 DP_EggLocation;
    /* 0x18 */ u16 DP_MetLocation;
    /* 0x1A */ u8 pokerus;
    /* 0x1B */ u8 pokeball;
    /* 0x1C */ u8 metLevel:7;
    u8 metGender:1;
    /* 0x1D */ u8 encounterType;
    /* 0x1E */ u8 HGSS_Pokeball;
    /* 0x1F */ s8 mood;
} PokemonDataBlockD;

typedef union {
    PokemonDataBlockA blockA;
    PokemonDataBlockB blockB;
    PokemonDataBlockC blockC;
    PokemonDataBlockD blockD;
} PokemonDataBlock;

struct BoxPokemon {
    /* 0x000 */ u32 pid;
    /* 0x004 */ u16 party_lock:1;
                u16 box_lock:1;
                u16 checksum_fail:1;
                u16 Unused:13;    // Might be used for validity checks
    /* 0x006 */ u16 checksum;  // Stored checksum of pokemon
    /* 0x008 */ PokemonDataBlock substructs[4];
};

union MailPatternData
{
    u16 raw;
    struct {
        u16 icon:12;
        u16 pal:4;
    };
};

#define MAILMSG_BANK_NONE           (0xFFFF)
#define MAILMSG_FIELDS_MAX          (2)

typedef struct MailMessage {
    u16 msg_bank;
    u16 msg_no;
    u16 fields[MAILMSG_FIELDS_MAX];
} MAIL_MESSAGE;

typedef struct Mail
{
    u32 author_otId;
    u8 author_gender;
    u8 author_language;
    u8 author_version;
    u8 mail_type;
    u16 author_name[7 + 1];
    union MailPatternData mon_icons[3];
    u16 forme_flags; // bitfield of three 5-bit values
    MAIL_MESSAGE unk_20[3];
} MAIL;

typedef struct PartyOnlyPokemon {
    /* 0x088 */ u32 status; // slp:3, psn:1, brn:1, frz:1, prz:1, tox:1, ...
    /* 0x08C */ u8 level;
    /* 0x08D */ u8 capsule;
    /* 0x08E */ u16 hp;
    /* 0x090 */ u16 maxHp;
    /* 0x092 */ u16 atk;
    /* 0x094 */ u16 def;
    /* 0x096 */ u16 speed;
    /* 0x098 */ u16 spatk;
    /* 0x09A */ u16 spdef;
    /* 0x09C */ MAIL mail;
    /* 0x0D4 */ CAPSULE sealCoords; // seal coords
} PARTYONLYMON;

struct PartyPokemon {
    /* 0x000 */ struct BoxPokemon box;
    /* 0x088 */ PARTYONLYMON party;
}; // size: 0xEC

struct Party
{
    s32 maxPossibleCount;
    s32 count;
    struct PartyPokemon members[6];
};

enum
{
    MON_DATA_PERSONALITY = 0,
    MON_DATA_PARTY_LOCK,
    MON_DATA_BOX_LOCK,
    MON_DATA_CHECKSUM_FAILED,
    MON_DATA_CHECKSUM,
    MON_DATA_SPECIES,
    MON_DATA_HELD_ITEM,
    MON_DATA_OTID,
    MON_DATA_EXPERIENCE,
    MON_DATA_FRIENDSHIP,
    MON_DATA_ABILITY,
    MON_DATA_MARKINGS,
    MON_DATA_GAME_LANGUAGE,
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPATK_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_COOL,
    MON_DATA_BEAUTY,
    MON_DATA_CUTE,
    MON_DATA_SMART,
    MON_DATA_TOUGH,
    MON_DATA_SHEEN,
    MON_DATA_SINNOH_CHAMP_RIBBON,
    MON_DATA_ABILITY_RIBBON,
    MON_DATA_GREAT_ABILITY_RIBBON,
    MON_DATA_DOUBLE_ABILITY_RIBBON,
    MON_DATA_MULTI_ABILITY_RIBBON,
    MON_DATA_PAIR_ABILITY_RIBBON,
    MON_DATA_WORLD_ABILITY_RIBBON,
    MON_DATA_ALERT_RIBBON,
    MON_DATA_SHOCK_RIBBON,
    MON_DATA_DOWNCAST_RIBBON,
    MON_DATA_CARELESS_RIBBON,
    MON_DATA_RELAX_RIBBON,
    MON_DATA_SNOOZE_RIBBON,
    MON_DATA_SMILE_RIBBON,
    MON_DATA_GORGEOUS_RIBBON,
    MON_DATA_ROYAL_RIBBON,
    MON_DATA_GORGEOUS_ROYAL_RIBBON,
    MON_DATA_FOOTPRINT_RIBBON,
    MON_DATA_RECORD_RIBBON,
    MON_DATA_HISTORY_RIBBON,
    MON_DATA_LEGEND_RIBBON,
    MON_DATA_RED_RIBBON,
    MON_DATA_GREEN_RIBBON,
    MON_DATA_BLUE_RIBBON,
    MON_DATA_FESTIVAL_RIBBON,
    MON_DATA_CARNIVAL_RIBBON,
    MON_DATA_CLASSIC_RIBBON,
    MON_DATA_PREMIER_RIBBON,
    MON_DATA_SINNOH_RIBBON_53,
    MON_DATA_MOVE1,
    MON_DATA_MOVE2,
    MON_DATA_MOVE3,
    MON_DATA_MOVE4,
    MON_DATA_MOVE1PP,
    MON_DATA_MOVE2PP,
    MON_DATA_MOVE3PP,
    MON_DATA_MOVE4PP,
    MON_DATA_MOVE1PPUP,
    MON_DATA_MOVE2PPUP,
    MON_DATA_MOVE3PPUP,
    MON_DATA_MOVE4PPUP,
    MON_DATA_MOVE1MAXPP,
    MON_DATA_MOVE2MAXPP,
    MON_DATA_MOVE3MAXPP,
    MON_DATA_MOVE4MAXPP,
    MON_DATA_HP_IV,
    MON_DATA_ATK_IV,
    MON_DATA_DEF_IV,
    MON_DATA_SPEED_IV,
    MON_DATA_SPATK_IV,
    MON_DATA_SPDEF_IV,
    MON_DATA_IS_EGG,
    MON_DATA_HAS_NICKNAME,
    MON_DATA_HOENN_COOL_RIBBON,
    MON_DATA_HOENN_COOL_RIBBON_SUPER,
    MON_DATA_HOENN_COOL_RIBBON_HYPER,
    MON_DATA_HOENN_COOL_RIBBON_MASTER,
    MON_DATA_HOENN_BEAUTY_RIBBON,
    MON_DATA_HOENN_BEAUTY_RIBBON_SUPER,
    MON_DATA_HOENN_BEAUTY_RIBBON_HYPER,
    MON_DATA_HOENN_BEAUTY_RIBBON_MASTER,
    MON_DATA_HOENN_CUTE_RIBBON,
    MON_DATA_HOENN_CUTE_RIBBON_SUPER,
    MON_DATA_HOENN_CUTE_RIBBON_HYPER,
    MON_DATA_HOENN_CUTE_RIBBON_MASTER,
    MON_DATA_HOENN_SMART_RIBBON,
    MON_DATA_HOENN_SMART_RIBBON_SUPER,
    MON_DATA_HOENN_SMART_RIBBON_HYPER,
    MON_DATA_HOENN_SMART_RIBBON_MASTER,
    MON_DATA_HOENN_TOUGH_RIBBON,
    MON_DATA_HOENN_TOUGH_RIBBON_SUPER,
    MON_DATA_HOENN_TOUGH_RIBBON_HYPER,
    MON_DATA_HOENN_TOUGH_RIBBON_MASTER,
    MON_DATA_HOENN_CHAMPION_RIBBON,
    MON_DATA_HOENN_WINNING_RIBBON,
    MON_DATA_HOENN_VICTORY_RIBBON,
    MON_DATA_HOENN_ARTIST_RIBBON,
    MON_DATA_HOENN_EFFORT_RIBBON,
    MON_DATA_HOENN_MARINE_RIBBON,
    MON_DATA_HOENN_LAND_RIBBON,
    MON_DATA_HOENN_SKY_RIBBON,
    MON_DATA_HOENN_COUNTRY_RIBBON,
    MON_DATA_HOENN_NATIONAL_RIBBON,
    MON_DATA_HOENN_EARTH_RIBBON,
    MON_DATA_HOENN_WORLD_RIBBON,
    MON_DATA_FATEFUL_ENCOUNTER,
    MON_DATA_GENDER,
    MON_DATA_FORM,
    MON_DATA_RESERVED_113,
    MON_DATA_RESERVED_114,
    MON_DATA_HGSS_EGG_MET_LOCATION,
    MON_DATA_HGSS_MET_LOCATION,
    MON_DATA_NICKNAME,
    MON_DATA_NICKNAME_2,
    MON_DATA_NICKNAME_3,
    MON_DATA_NICKNAME_4,
    MON_DATA_UNK_121,
    MON_DATA_GAME_VERSION,
    MON_DATA_COOL_RIBBON,
    MON_DATA_COOL_RIBBON_GREAT,
    MON_DATA_COOL_RIBBON_ULTRA,
    MON_DATA_COOL_RIBBON_MASTER,
    MON_DATA_BEAUTY_RIBBON,
    MON_DATA_BEAUTY_RIBBON_GREAT,
    MON_DATA_BEAUTY_RIBBON_ULTRA,
    MON_DATA_BEAUTY_RIBBON_MASTER,
    MON_DATA_CUTE_RIBBON,
    MON_DATA_CUTE_RIBBON_GREAT,
    MON_DATA_CUTE_RIBBON_ULTRA,
    MON_DATA_CUTE_RIBBON_MASTER,
    MON_DATA_SMART_RIBBON,
    MON_DATA_SMART_RIBBON_GREAT,
    MON_DATA_SMART_RIBBON_ULTRA,
    MON_DATA_SMART_RIBBON_MASTER,
    MON_DATA_TOUGH_RIBBON,
    MON_DATA_TOUGH_RIBBON_GREAT,
    MON_DATA_TOUGH_RIBBON_ULTRA,
    MON_DATA_TOUGH_RIBBON_MASTER,
    MON_DATA_SINNOH_RIBBON_143,
    MON_DATA_OT_NAME,
    MON_DATA_OT_NAME_2,
    MON_DATA_EGG_MET_YEAR,
    MON_DATA_EGG_MET_MONTH,
    MON_DATA_EGG_MET_DAY,
    MON_DATA_MET_YEAR,
    MON_DATA_MET_MONTH,
    MON_DATA_MET_DAY,
    MON_DATA_EGG_MET_LOCATION,
    MON_DATA_MET_LOCATION,
    MON_DATA_POKERUS,
    MON_DATA_POKEBALL,
    MON_DATA_MET_LEVEL,
    MON_DATA_MET_GENDER,
    MON_DATA_ENCOUNTER_TYPE,
    MON_DATA_RESERVED_159,
    MON_DATA_STATUS,
    MON_DATA_LEVEL,
    MON_DATA_CAPSULE,
    MON_DATA_HP,
    MON_DATA_MAXHP,
    MON_DATA_ATTACK,
    MON_DATA_DEFENSE,
    MON_DATA_SPEED,
    MON_DATA_SPECIAL_ATTACK,
    MON_DATA_SPECIAL_DEFENSE,
    MON_DATA_MAIL_STRUCT,
    MON_DATA_SEAL_COORDS,
    MON_DATA_SPECIES_EXISTS,
    MON_DATA_SANITY_IS_EGG,
    MON_DATA_SPECIES_OR_EGG,
    MON_DATA_IVS_WORD,
    MON_DATA_UNK_176,
    MON_DATA_TYPE_1,
    MON_DATA_TYPE_2,
    MON_DATA_SPECIES_NAME,
    MON_DATA_DP_POKEBALL,
    MON_DATA_SHINY_LEAF_A,
    MON_DATA_SHINY_LEAF_B,
    MON_DATA_SHINY_LEAF_C,
    MON_DATA_SHINY_LEAF_D,
    MON_DATA_SHINY_LEAF_E,
    MON_DATA_SHINY_LEAF_CROWN,
    MON_DATA_MOOD,
    MON_DATA_END
};

struct OVERWORLD_TAG
{
    u16 tag;
    u16 gfx; // index in a081
    u16 callback_params;
};


// frick new formes
struct PLIST_DATA
{
    /* 0x00 */ struct Party *pp;
    /* 0x04 */ void *myitem;
    /* 0x08 */ void *mailblock;
    /* 0x0C */ void *cfg;
    /* 0x10 */ void *tvwk;
    /* 0x14 */ void *reg;
    /* 0x18 */ void *scwk;
    /* 0x1C */ void *fsys;
               void *padsmth;
    /* 0x20+4 */ u8 mode;
    /* 0x21+4 */ u8 type;
    /* 0x22+4 */ u8 ret_sel;
    /* 0x23+4 */ u8 ret_mode;
    /* 0x24+4 */ u16 item; // this is actually 0x28
    /* 0x26+4 */ u16 move;
    /* 0x28+4 */ u8 movepos;
    /* 0x29+4 */ u8 con_mode;
    /* 0x2A+4 */ u8 con_type;
    /* 0x2B+4 */ u8 con_rank;
    /* 0x2C+4 */ u8 in_num[6];
    /* 0x32+4 */ u8 in_min:4;
                 u8 in_max:4;
    /* 0x33+4 */ u8 in_lv;
    /* 0x34+4 */ s32 lv_cnt;
    /* 0x38+4 */ u16 after_mons;
    /* 0x3C+4 */ s32 shinka_cond;
};

struct PLIST_WORK
{
    u8 padding_x0[0x654];
    struct PLIST_DATA *dat;
    u8 padding_x658[0xC65-0x658];
    u8 pos;
};


struct SAVE_MISC_DATA;


// defines from pokeheartgold + new ones
typedef enum EvoMethod
{
    EVO_NONE = 0,
    EVO_FRIENDSHIP,
    EVO_FRIENDSHIP_DAY,
    EVO_FRIENDSHIP_NIGHT,
    EVO_LEVEL,
    EVO_TRADE,
    EVO_TRADE_ITEM,
    EVO_STONE,
    EVO_LEVEL_ATK_GT_DEF,
    EVO_LEVEL_ATK_EQ_DEF,
    EVO_LEVEL_ATK_LT_DEF,
    EVO_LEVEL_PID_LO,
    EVO_LEVEL_PID_HI,
    EVO_LEVEL_NINJASK,
    EVO_LEVEL_SHEDINJA,
    EVO_BEAUTY,
    EVO_STONE_MALE,
    EVO_STONE_FEMALE,
    EVO_ITEM_DAY,
    EVO_ITEM_NIGHT,
    EVO_HAS_MOVE,
    EVO_OTHER_PARTY_MON,
    EVO_LEVEL_MALE,
    EVO_LEVEL_FEMALE,
    EVO_CORONET,
    EVO_ETERNA,
    EVO_ROUTE217,
    EVO_LEVEL_DAY,
    EVO_LEVEL_NIGHT,
    EVO_LEVEL_DUSK,
    EVO_LEVEL_RAIN,
    EVO_HAS_MOVE_TYPE,
    EVO_LEVEL_DARK_TYPE_MON_IN_PARTY,
    EVO_TRADE_SPECIFIC_MON,
    EVO_LEVEL_NATURE_AMPED,
    EVO_LEVEL_NATURE_LOW_KEY,
    EVO_AMOUNT_OF_CRITICAL_HITS,
    EVO_HURT_IN_BATTLE_AMOUNT,
    //EVO_DARK_SCROLL,  // implemented through a forme-change-esque cut scene
    //EVO_WATER_SCROLL, // implemented through a forme-change-esque cut scene
} EvoMethod;

typedef enum {
    EVOCTX_LEVELUP,
    EVOCTX_TRADE,
    EVOCTX_ITEM_CHECK,
    EVOCTX_ITEM_USE,
} EvolveContext;

struct Evolution {
    u16 method;
    u16 param;
    u16 target;
};

typedef struct
{
    u16 arc_no;
    u16 index_chr;
    u16 index_pal;
    u16 strike_mons;
    u8 form_no;
    u8 dummy[3];
    u32 personal_rnd;
} MON_PIC;

struct FormData
{
    u16 species;

    u16 form_no:15;
    u16 need_rev:1;

    u16 file;
};

typedef struct EncounterInfo
{
    u32 trainerID;
    BOOL unk4;
    BOOL unk8;
    u8 level;
    u8 isEgg;
    u8 ability;
    u8 unkE[2];
    u8 unk11;
} EncounterInfo; // size = 0x12


// Daycare structures
typedef struct DaycareMail {
    struct Mail mail;
    u16 ot_name[7 + 1];
    u16 nickname[10 + 1];
    u8 padding_5E[2];
} DaycareMail;

typedef struct DaycareMon {
    struct BoxPokemon mon;
    DaycareMail mail;
    u32 steps;
} DaycareMon;

typedef struct Daycare {
    DaycareMon mons[2];
    u32 egg_pid;
    u8 egg_cycles;
    u8 padding_1DD[3];
} Daycare;


// BattleMove fields for GetMoveData below
enum
{
    MOVE_DATA_EFFECT,
    MOVE_DATA_PSS_SPLIT,
    MOVE_DATA_BASE_POWER,
    MOVE_DATA_TYPE,
    MOVE_DATA_ACCURACY,
    MOVE_DATA_BASE_PP,
    MOVE_DATA_SECONDARY_EFFECT_CHANCE,
    MOVE_DATA_TARGET,
    MOVE_DATA_PRIORITY,
    MOVE_DATA_FLAGS,
    MOVE_DATA_UNK,
};


// natures
#define NATURE_HARDY    (0)
#define NATURE_LONELY   (1)
#define NATURE_BRAVE    (2)
#define NATURE_ADAMANT  (3)
#define NATURE_NAUGHTY  (4)
#define NATURE_BOLD     (5)
#define NATURE_DOCILE   (6)
#define NATURE_RELAXED  (7)
#define NATURE_IMPISH   (8)
#define NATURE_LAX      (9)
#define NATURE_TIMID   (10)
#define NATURE_HASTY   (11)
#define NATURE_SERIOUS (12)
#define NATURE_JOLLY   (13)
#define NATURE_NAIVE   (14)
#define NATURE_MODEST  (15)
#define NATURE_MILD    (16)
#define NATURE_QUIET   (17)
#define NATURE_BASHFUL (18)
#define NATURE_RASH    (19)
#define NATURE_CALM    (20)
#define NATURE_GENTLE  (21)
#define NATURE_SASSY   (22)
#define NATURE_CAREFUL (23)
#define NATURE_QUIRKY  (24)


#define MAX_EVOS_PER_POKE (9)


#define gDimorphismTable ((u8 *)(0x020FECAE))
#define EGG_MOVES_PER_MON 16 // need to go through later and make this editable
#define NUM_EGG_MOVES_TOTAL 8000


/**Trainer Data File Bitfield**/
#define TRAINER_DATA_TYPE_NOTHING 0x00
#define TRAINER_DATA_TYPE_MOVES 0x01
#define TRAINER_DATA_TYPE_ITEMS 0x02
#define TRAINER_DATA_TYPE_ABILITY 0x04
#define TRAINER_DATA_TYPE_BALL 0x08
#define TRAINER_DATA_TYPE_IV_EV_SET 0x10
#define TRAINER_DATA_TYPE_NATURE_SET 0x20
#define TRAINER_DATA_TYPE_SHINY_LOCK 0x40
#define TRAINER_DATA_TYPE_ADDITIONAL_FLAGS 0x80 //whether or not to read extra flags in trpoke entry


/**Trainer Pokemon File Extra Bitfield**/
#define TRAINER_DATA_EXTRA_TYPE_NOTHING 0x00
#define TRAINER_DATA_EXTRA_TYPE_STATUS 0x01
#define TRAINER_DATA_EXTRA_TYPE_HP 0x02
#define TRAINER_DATA_EXTRA_TYPE_ATK 0x04
#define TRAINER_DATA_EXTRA_TYPE_DEF 0x08
#define TRAINER_DATA_EXTRA_TYPE_SPEED 0x10
#define TRAINER_DATA_EXTRA_TYPE_SP_ATK 0x20
#define TRAINER_DATA_EXTRA_TYPE_SP_DEF 0x40
#define TRAINER_DATA_EXTRA_TYPE_TYPES 0x80
#define TRAINER_DATA_EXTRA_TYPE_PP_COUNTS 0x100
#define TRAINER_DATA_EXTRA_TYPE_NICKNAME 0x200


/**
 *  @brief allocate enough space for a PartyPokemon and zero it out
 *
 *  @param heapid heap to allocate the PartyPokemon on
 *  @return pointer to zero'd PartyPokemon
 */
struct PartyPokemon *__attribute__((long_call)) AllocMonZeroed(u32 heapid);

/**
 *  @brief zero out a PartyPokemon
 *
 *  @param pokemon PartyPokemon to 0 out
 */
void __attribute__((long_call)) ZeroMonData(struct PartyPokemon *pokemon);

/**
 *  @brief initialize PartyPokemon with specified parameters
 *
 *  @param pp PartyPokemon to initialize
 *  @param species species index
 *  @param level level to set
 *  @param ivs iv's to set to.  random if > 31
 *  @param chr nature?
 */
void __attribute__((long_call)) PokeParaSetChr(struct PartyPokemon *pp, u16 species, u8 level, u8 ivs, u8 chr);

/**
 *  @brief initialize PartyPokemon with specified parameters
 *
 *  @param pp PartyPokemon to initialize
 *  @param mons_no species index
 *  @param level level to set
 *  @param ivs iv's to set to.  random if > 31
 *  @param rndflag if TRUE set pid to rnd
 *  @param rnd if rndflag is TRUE, personality id
 *  @param idflag if TRUE set ot id to id
 *  @param id if idflag is TRUE, ot id
 */
void __attribute__((long_call)) PokeParaSet(struct PartyPokemon *pp, int mons_no, int level, int ivs, int rndflag, u32 rnd, int idflag, u32 id);

/**
 *  @brief set PartyPokemon as seen in the pokédex
 *
 *  @param zw pokédex save structure, i.e. SaveData_GetDexPtr(SaveBlock2_get())
 *  @param pp PartyPokemon whose species to register as seen
 */
void __attribute__((long_call)) SetPokemonSee(void *zw, struct PartyPokemon *pp);

/**
 *  @brief set PartyPokemon as caught in the pokédex
 *
 *  @param zw pokédex save structure, i.e. SaveData_GetDexPtr(SaveBlock2_get())
 *  @param pp PartyPokemon whose species to register as caught
 */
void __attribute__((long_call)) SetPokemonGet(void *zw, struct PartyPokemon *pp);

/**
 *  @brief grab PartyPokemon or BoxPokemon that is currently being viewed in the PC
 *
 *  @param ptr pc work structure
 *  @return BoxPokemon or PartyPokemon that is currently being viewed in the PC
 */
void *__attribute__((long_call)) PokeStatusPokeParamGet(void *ptr);

/**
 *  @brief recalculate a PartyPokemon's stats
 *
 *  @param pp PartyPokemon whose stats to recalculate
 */
void __attribute__((long_call)) RecalcPartyPokemonStats(struct PartyPokemon *pp);

/**
 *  @brief reset a PartyPokemon's ability
 *
 *  @param pp PartyPokemon whose ability to reset
 */
void __attribute__((long_call)) ResetPartyPokemonAbility(void *pp);

/**
 *  @brief initialize PartyPokemon with specified parameters
 *
 *  @param pp PartyPokemon to intialize
 *  @param pokeno species index
 *  @param level level to set to
 *  @param ivs iv's to set to.  random if > 31
 *  @param sex sex to aim for, specifically POKEMON_GENDER_* constant
 *  @param chr nature?
 *  @param unownLetter unown letter to set to
 */
void __attribute__((long_call)) PokeParaSetSexChr(struct PartyPokemon *pp, u16 pokeno, u8 level, u8 ivs, u8 sex, u8 chr, u8 unownLetter);

/**
 *  @brief get specific field from an encrypted PartyPokemon
 *
 *  @param mon PartyPokemon to grab data from
 *  @param field MON_DATA_* constant to determine which data to grab
 *  @param buffer NULL or pointer to store return array at
 *  @return requested data; data may be in buffer if an array was requested (i.e. MON_DATA_NICKNAME)
 */
u32 __attribute__((long_call)) GetMonData(struct PartyPokemon *mon, int field, void *buffer);

/**
 *  @brief set specific field on an encrypted PartyPokemon
 *
 *  @param mon PartyPokemon to set data on
 *  @param field MON_DATA_* constant to determine which data to set
 *  @param buffer pointer to data to set.  always a pointer, even for simple values
 */
void __attribute__((long_call)) SetMonData(struct PartyPokemon *mon, int field, void *buffer);

/**
 *  @brief sanitize the form for species that already have forms in game (set to 0 if invalid)
 *
 *  @param mons_no species index
 *  @param form_no form number
 *  @return corrected form number
 */
u8 __attribute__((long_call)) SanitizeFormNumber(u16 mons_no, u8 form_no);

/**
 *  @brief set specific field on an encrypted BoxPokemon
 *
 *  @param boxmon BoxPokemon to grab data from
 *  @param field MON_DATA_* constant to determine which data to grab
 *  @param buffer NULL or pointer to store return array at
 *  @return requested data; data may be in buffer if an array was requested (i.e. MON_DATA_NICKNAME)
 */
u32 __attribute__((long_call)) GetBoxMonData(struct BoxPokemon *boxmon, int field, void *buffer);

/**
 *  @brief set specific field on an encrypted BoxPokemon
 *
 *  @param mon BoxPokemon to set data on
 *  @param field MON_DATA_* constant to determine which data to set
 *  @param buffer pointer to data to set.  always a pointer, even for simple values
 */
void  __attribute__((long_call)) SetBoxMonData(struct BoxPokemon *boxmon, int id, const void *buf);

/**
 *  @brief grab the pointer to a member in a Party
 *
 *  @param party Party whose member to grab
 *  @param pos position to grab
 *  @return PartyPokemon requested
 */
struct PartyPokemon * __attribute__((long_call)) PokeParty_GetMemberPointer(struct Party *party, int pos);

/**
 *  @brief grab personal field accounting for form (for vanilla forms)
 *
 *  @param mons_no base species index
 *  @param form_no form number
 *  @param para PERSONAL_* constant representing data requested
 *  @return requested data from the personal narc
 */
u32 __attribute__((long_call)) PokeFormNoPersonalParaGet(int mons_no, int form_no, int para);

/**
 *  @brief get the gender of a BoxPokemon
 *
 *  @param boxmon BoxPokemon whose gender to grab
 *  @return POKEMON_GENDER_* constant representing gender of the BoxPokemon
 */
u8 __attribute__((long_call)) GetBoxMonGender(struct BoxPokemon *boxmon);

/**
 *  @brief get the gender of a pokémon given species and pid
 *
 *  @param monsno species index
 *  @param rnd personality id
 *  @return POKEMON_GENDER_* constant
 */
u8 __attribute__((long_call)) PokeSexGetMonsNo(u16 monsno, u32 rnd);

/**
 *  @brief reencrypt a BoxPokemon for easy access to fields (undo BoxMonSetFastModeOn)
 *
 *  @see BoxMonSetFastModeOn
 *  @param boxmon BoxPokemon to reencrypt
 *  @param trigger TRUE to set fast mode off; FALSE do nothing
 *  @return TRUE if fast mode was set off; FALSE otherwise
 */
BOOL __attribute__((long_call)) BoxMonSetFastModeOff(struct BoxPokemon *boxmon, BOOL trigger);

/**
 *  @brief decrypt a BoxPokemon structure for easy access to fields (fast mode)
 *
 *  @param boxmon BoxPokemon to decrypt
 *  @return TRUE if successfully decrypted BoxPokemon, FALSE otherwise
 */
BOOL __attribute__((long_call)) BoxMonSetFastModeOn(struct BoxPokemon *boxmon);

/**
 *  @brief grab a BoxPokemon from a pokémon in the daycare
 *
 *  @param daycare Daycare structure ( i.e. Save_Daycare_Get(SaveBlock2_get()) )
 *  @param idx which daycare BoxPokemon to grab
 *  @return BoxPokemon requested
 */
struct BoxPokemon *__attribute__((long_call)) Daycare_GetBoxMonI(Daycare *daycare, int idx);

/**
 *  @brief set a PartyPokemon's personality
 *
 *  @param mon PartyPokemon whose personality to change
 *  @param personal_rnd new pid
 */
void __attribute__((long_call)) SetMonPersonality(struct PartyPokemon *mon, u32 personal_rnd);

/**
 *  @brief grab nature from personality
 *
 *  @param personality pid from pokémon
 *  @return nature (i.e. personality % 25)
 */
u8 __attribute__((long_call)) PokeNatureGet(u32 personality);

/**
 *  @brief intialize a BoxPokemon's moves depending on level and such that are already set
 *
 *  @param boxmon BoxPokemon whose moves to initialize
 */
void __attribute__((long_call)) FillInBoxMonLearnset(struct BoxPokemon *boxmon);

/**
 *  @brief get data from personal narc for a species
 *
 *  @param species species index to grab from the narc for
 *  @param parameter PERSONAL_* constant to request for
 *  @return data requested
 */
u32 __attribute__((long_call)) PokePersonalParaGet(int species, int parameter);

/**
 *  @brief get the experience required to reach a specific level for a species
 *
 *  @param species species to get experience curve for
 *  @param level level to get the experience for
 *  @return experience required to reach level specified
 */
u32 __attribute__((long_call)) PokeLevelExpGet(int species, int level);

/**
 *  @brief intiailize a BoxPokemon structure with zeros
 *
 *  @param BoxPokemon to initialize
 */
void __attribute__((long_call)) BoxMonInit(struct BoxPokemon *boxmon);

/**
 *  @brief handle giratina's form change with a BoxPokemon
 *         handles checking if the BoxPokemon is actually giratina and such
 *
 *  @param bp BoxPokemon to check for a form change
 */
void __attribute__((long_call)) GiratinaBoxPokemonFormChange(struct BoxPokemon *bp);

/**
 *  @brief check if the gracidea flower can be used on a PartyPokemon
 *
 *  @param pp PartyPokemon to check for gracidea validity
 *  @return TRUE if the gracidea can be used on the PartyPokemon
 */
BOOL __attribute__((long_call)) GrashideaFeasibleCheck(struct PartyPokemon *pp);

/**
 *  @brief load in the party overlay
 *
 *  @param wk poke list work
 */
void __attribute__((long_call)) PokeList_FormDemoOverlayLoad(struct PLIST_WORK *wk);

/**
 *  @brief add a PartyPokemon to an available slot in the Party
 *
 *  @param party Party to add to
 *  @param poke PartyPokemon to add
 *  @return TRUE if the add was successful; FALSE otherwise
 */
BOOL __attribute__((long_call)) PokeParty_Add(struct Party *party, struct PartyPokemon *poke);

/**
 *  @brief delete a PartyPokemon from a Party
 *
 *  @param party Party to delete from
 *  @param pos position in Party to delete
 */
void __attribute__((long_call)) PokeParty_Delete(struct Party *party, u32 pos);

/**
 *  @brief task to handle party rendering
 *
 *  @param proc task structure
 *  @param seq step in rendering
 *  @return TRUE if should end?
 */
u32 __attribute__((long_call)) PokeListProc_End(void *proc, int *seq);

/**
 *  @brief return the amount of experience required to level up given a PartyPokemon
 *
 *  @param pp PartyPokemon to grab experience for
 *  @return amount of experience required to level up
 */
u32 __attribute__((long_call)) PokeParaLevelExpGet(struct PartyPokemon *pp);

/**
 *  @brief check if a PartyPokemon should level up
 *
 *  @param pp PartyPokemon to potentially level up
 *  @return TRUE if the PartyPokemon should level up; FALSE otherwise
 */
u32 __attribute__((long_call)) PokeLevelUpCheck(struct PartyPokemon *pp);

/**
 *  @brief check if a Party has a specific species
 *
 *  @param party Party to check through
 *  @param species species index
 *  @return TRUE if the Party contains a PartyPokemon with the requested species; FALSE otherwise
 */
BOOL __attribute__((long_call)) PartyHasMon(struct Party *party, u16 species);

/**
 *  @brief check if a PartyPokemon has a move
 *
 *  @param mon PartyPokemon whose moves to check
 *  @param move move to check for
 *  @return TRUE if the PartyPokemon has the move; FALSE otherwise
 */
BOOL __attribute__((long_call)) MonHasMove(struct PartyPokemon *mon, u16 move);

/**
 *  @brief see if passed species has sexual dimorphism that would be visible in the overworld
 *
 *  @param species species index
 *  @return TRUE if the species has sexual dimorphism visible in the overworld; FALSE otherwise
 */
BOOL __attribute__((long_call)) does_species_have_dimorphism(u32 species);

/**
 *  @brief grab the base overworld data file number for a species
 *
 *  @param species species index
 *  @return requested base overworld data file number
 */
u32 __attribute__((long_call)) get_ow_data_file_num(u32 species);

/**
 *  @brief intialize various values to a PartyPokemon (location caught, caught ball, etc.)
 *
 *  @param pp PartyPokemon to initialize
 *  @param profile save data profile, i.e. Sav2_PlayerData_GetProfileAddr(SaveBlock2_get())
 *  @param item item to register as caught ball?  not held item
 *  @param ball caught ball
 *  @param encounterType encounter type
 *  @param heapId heap to use for memory allocations
 *  @return 
 */
BOOL __attribute__((long_call)) sub_020720FC(struct PartyPokemon *pp, void *profile, u16 item, u16 ball, u32 encounterType, int heapId);

/**
 *  @brief update pokédex status for the given PartyPokemon's species
 *
 *  @param saveData player save data, i.e. SaveBlock2_get()
 *  @param pokemon PartyPokemon whose species should update the pokédex with
 */
void __attribute__((long_call)) UpdatePokedexWithReceivedSpecies(void *saveData, struct PartyPokemon *pokemon);

/**
 *  @brief fill in a BoxPokemon's default moves
 *
 *  @param pokemon BoxPokemon whose initial moves should be filled in
 */
void __attribute__((long_call)) InitBoxMonMoveset(struct BoxPokemon *pokemon);

/**
 *  @brief potentially set the held item of a PartyPokemon to one that it has specified in its personal data
 *
 *  @param pokemon PartyPokemon whose held item to set
 *  @param fight_type current battle type
 *  @param item_type 1 if compound eyes is present, 0 otherwise
 */
void __attribute__((long_call)) WildMonSetRandomHeldItem(struct PartyPokemon *pokemon, u32 fight_type, u32 item_type);

/**
 *  @brief register unown form as seen in the pokédex
 *
 *  @param pokemon PartyPokemon whose unown form should be registered as seen in the pokédex
 *  @return TRUE if was successful; FALSE otherwise
 */
BOOL __attribute__((long_call)) GrabAndRegisterUnownForm(struct PartyPokemon *pokemon);

/**
 *  @brief check if PartyPokemon is shiny
 *
 *  @param pokemon PartyPokemon to check shininess on
 *  @return TRUE if pokemon is shiny; FALSE otherwise
 */
BOOL __attribute__((long_call)) MonIsShiny(struct PartyPokemon *pokemon);

/**
 *  @brief check if BoxPokemon is shiny
 *
 *  @param pokemon BoxPokemon to check shininess on
 *  @return TRUE if pokemon is shiny; FALSE otherwise
 */
BOOL __attribute__((long_call)) BoxMonIsShiny(struct BoxPokemon *pokemon);

/**
 *  @brief initialize a Party
 *
 *  @param party Party to initialize
 *  @param max amount of members
 */
void __attribute__((long_call)) PokeParty_Init(struct Party *party, int max);

/**
 *  @brief grab trainer party data from ARC_TRAINER_PARTY_DATA
 *
 *  @param tr_id trainer id
 *  @param tpd buffer to dump to
 */
void __attribute__((long_call)) TT_TrainerPokeDataGet(int tr_id, void *tpd);

/**
 *  @brief grab trainer sex from trainer class read from ARC_TRAINER_DATA
 *
 *  @param trtype trainer class
 *  @return trainer sex; 1 if female, 0 if male
 */
u8 __attribute__((long_call)) TT_TrainerTypeSexGet(int trtype);

/**
 *  @brief set ball seal on a trainer PartyPokemon
 *
 *  @param index ball seal to set
 *  @param pp PartyPokemon to set seals on
 *  @param heap memory heap to use
 *  @return 
 */
u32 __attribute__((long_call)) TrainerCBSet(int index, struct PartyPokemon *pp, int heap);

/**
 *  @brief try and generate a pid that forces a specific gender
 *
 *  @param species species index
 *  @param formnum form number
 *  @param a2 ability slot
 *  @param personality generated personality id
 */
void __attribute__((long_call)) try_force_gender_maybe(int species, int formnum, u8 a2, u32 *personality);

/**
 *  @brief set a PartyPokemon's friendship to 0 if it has the move frustration
 *
 *  @param pp PartyPokemon to manipulate
 */
void __attribute__((long_call)) TrainerMonHandleFrustration(struct PartyPokemon *pp);

/**
 *  @brief overwrite a PartyPokemon's move with a different one
 *
 *  @param pp PartyPokemon whose moves to mess with
 *  @param movenum move index to overwrite with
 *  @param pos which move position to overwrite
 */
void __attribute__((long_call)) SetPartyPokemonMoveAtPos(struct PartyPokemon *pp, u16 movenum, u8 pos);

/**
 *  @brief seed PRNG so that future gf_rand() calls are adjusted
 *
 *  @param seed seed to start the PRNG from moving forward
 */
void __attribute__((long_call)) gf_srand(u32 seed);

/**
 *  @brief grab arceus type from held effect
 *
 *  @param held_effect held item effect
 *  @return the type that arceus would be with this held item effect
 */
u8 __attribute__((long_call)) GetArceusType(u16 held_effect);

/**
 *  @brief something with eggs
 *
 *  @param mapsectype 
 *  @param offset variable value
 *  @return 
 */
int __attribute__((long_call)) sub_02017FE4(u32 mapsectype, u32);

/**
 *  @brief set egg stats for a PartyPokemon
 *
 *  @param pokemon PartyPokemon to manipulate
 *  @param species species of egg
 *  @param metLocation met location for the egg
 *  @param profile profile in save data, i.e. Sav2_PlayerData_GetProfileAddr(SaveBlock2_get())
 *  @param a4 
 *  @param a5 
 */
void __attribute__((long_call)) SetEggStats(struct PartyPokemon *pokemon, int species, u8 metLocation, void *profile, int a4, int a5);

/**
 *  @brief set togepi egg personality and id in the save
 *         used for the professor elm call when he tells you to stop by with the togepi when it hatches
 *
 *  @param saveMiscData misc save data, i.e. Sav2_Misc_get(SaveBlock2_get())
 */
void __attribute__((long_call)) SaveMisc_SetTogepiPersonalityGender(struct SAVE_MISC_DATA * saveMiscData, int personality, u8 gender);

/**
 *  @brief grab hatched togepi pid and gender
 *
 *  @param saveMiscData misc save data, i.e. Sav2_Misc_get(SaveBlock2_get())
 *  @param pid pointer to store saved togepi pid to
 *  @param gender pointer to store saved togepi gender to
 */
void __attribute__((long_call)) SaveMisc_GetTogepiPersonalityGender(struct SAVE_MISC_DATA * saveMiscData, int *pid, u8 *gender);

/**
 *  @brief clear a PartyPokemon and carry over certain persistent values
 *
 *  @param pokemon PartyPokemon to use for hatching
 *  @param heapId heap to use for memory allocations 
 */
void __attribute__((long_call)) sub_0206D038(struct PartyPokemon *pokemon, u32 heapId);

/**
 *  @brief load terminated species name into array
 *
 *  @param species species name to load
 *  @param heap_id heap to use for memory allocations
 *  @param dest destination array to throw the species name into
 */
void __attribute__((long_call)) GetSpeciesNameIntoArray(u16 species, u32 heap_id, u16 *dest);

/**
 *  @brief add a PartyPokemon to wild battler team
 *
 *  @param pp uninitialized PartyPokemon to init and add to enemy team
 *  @param rodType rod type (255 if N/A)
 *  @param encInfo 
 *  @param encArea 
 *  @param encounterType 
 *  @param battler battler whose team to add to
 *  @param bw battle work structure
 *  @return TRUE if PartyPokemon was successfully generated and added; FALSE otherwise
 */
u32 __attribute__((long_call)) SetEncountData(struct PartyPokemon *pp, u32 rodType, void *encInfo, void *encArea, u32 encounterType, u32 battler, void *bw);

/**
 *  @brief add a PartyPokemon to wild battler team for swarms potentially
 *
 *  @param fsys field system structure
 *  @param pp uninitialized PartyPokemon to init and add to enemy team
 *  @param rodType rod type (255 if N/A)
 *  @param encInfo 
 *  @param encounterType 
 *  @param battler battler whose team to add to
 *  @param bw battle work structure
 *  @return TRUE if PartyPokemon was successfully generated and added; FALSE otherwise
 */
u32 __attribute__((long_call)) SetEncountDataSwarm_maybe(void *fsys, struct PartyPokemon *pp, u32 rodType, void *encInfo, u32 encounterType, u32 battler, void *bw);

/**
 *  @brief initialize a PartyPokemon given a BoxPokemon
 *
 *  @param src BoxPokemon to fill out to a PartyPokemon
 *  @param dest PartyPokemon return
 */
void __attribute__((long_call)) CopyBoxPokemonToPokemon(const struct BoxPokemon *src, struct PartyPokemon *dest);

/**
 *  @brief grab experience needed to reach a specific level by growth rate
 *
 *  @param growthrate GROWTH_* constant as defined in personal entry
 *  @param level level asked for
 *  @return experience needed to reach specified level
 */
int __attribute__((long_call)) GetExpByGrowthRateAndLevel(int growthrate, u32 level);


#define gIconPalTable ((u8 *)(0x023D8000 + START_ADDRESS))

// defined in src/pokemon.c

/**
 *  @brief set up the indices for the new form system pictures.  if necessary, loop through the form table, searching for the new form index to load sprites from
 *         this function does not account for existing forms already covered by otherpoke.narc
 *
 *  @param picdata MON_PIC structure to store values in
 *  @param mons_no species of pokémon
 *  @param dir direction of the pokémon
 *  @param col shininess of the pokémon
 *  @param form_no form number of the pokémon
 *  @return FALSE if there is no need to look through the form table or a matching entry is not found; TRUE otherwise
 */
BOOL __attribute__((long_call)) GetOtherFormPic(MON_PIC *picdata, u16 mons_no, u8 dir, u8 col, u8 form_no);

/**
 *  @brief pass species and form to get new species for personal narc, parsing through form table if necessary
 *
 *  @param mons_no base species
 *  @param form_no form number
 *  @return adjusted species for personal narc
 */
int __attribute__((long_call)) PokeOtherFormMonsNoGet(int mons_no, int form_no);

/**
 *  @brief pass species and form to get new species
 *
 *  @param mons_no species
 *  @param form_no form number
 *  @return adjusted species given base species and form number
 */
u16 __attribute__((long_call)) GetSpeciesBasedOnForm(int mons_no, int form_no);

/**
 *  @brief pass adjusted species and return base species
 *
 *  @param mons_no species that has already been adjusted by form number by GetSpeciesBasedOnForm
 *  @return base species
 */
u16 __attribute__((long_call)) GetOriginalSpeciesBasedOnAdjustedForm(u32 mons_no);

/**
 *  @brief grab index in ARC_POKEICON from original species, egg status, and form number
 *
 *  @param mons base species index
 *  @param egg TRUE if pokémon is an egg; FALSE otherwise
 *  @param form_no form number
 *  @return icon index in ARC_POKEICON
 */
u32 __attribute__((long_call)) PokeIconIndexGetByMonsNumber(u32 mons, u32 egg, u32 form_no);

/**
 *  @brief grab form if necessary for icons from BoxPokemon structure
 *
 *  @param ppp BoxPokemon structure to grab form for icon
 *  @return form if applicable; 0 otherwise
 */
u16 __attribute__((long_call)) PokeIconCgxPatternGet(struct BoxPokemon *ppp);

/**
 *  @brief grab index for pal number for the icon that is loaded
 *
 *  @param mons species index
 *  @param form form number
 *  @param isegg TRUE if is egg
 *  @return index for palette number for the icon to load
 */
u32 __attribute__((long_call)) PokeIconPalNumGet(u32 mons, u32 form, u32 isegg);

/**
 *  @brief grab mon icon palette number, 0-2
 *
 *  @param mons species index
 *  @param form form number
 *  @param isegg TRUE if pokémon is in an egg
 *  @return palette number 0-2
 */
u32 __attribute__((long_call)) GetMonIconPalette(u32 mons, u32 form, u32 isegg);

/**
 *  @brief grab pokémon overworld number
 *
 *  @param species base species
 *  @return pokémon overworld number
 */
u16 __attribute__((long_call)) GetPokemonOwNum(u16 species);

/**
 *  @brief grab the hidden ability for a species and form
 *
 *  @param species pokémon species
 *  @param form form number
 *  @return hidden ability of specific pokémon
 */
u16 __attribute__((long_call)) GetMonHiddenAbility(u16 species, u32 form);

/**
 *  @brief set a box mon's ability--modified to account for hidden ability flag--should only be used in scripted wild encounters/givepokemon contexts
 *
 *  @param boxmon struct BoxPokemon whose ability to set when being generated
 */
void __attribute__((long_call)) SetBoxMonAbility(struct BoxPokemon *boxmon);

/**
 *  @brief get species base experience, modified for form.  base experience is no longer in personal
 *
 *  @param species species index
 *  @param form form number
 *  @return base experience
 */
u32 __attribute__((long_call)) GetSpeciesBaseExp(u32 species, u32 form);

//struct OVERWORLD_TAG * __attribute__((long_call)) grab_overworld_ptr(u16 tag);

//u16 __attribute__((long_call)) get_a081_index_from_tag(u16 tag);

//u32 __attribute__((long_call)) grab_overworld_a081_index(u16 species, u32 form, u32 isFemale);

/**
 *  @brief get genesect type from held item
 *
 *  @param item held item
 *  @return type from held item
 */
u32 __attribute__((long_call)) GetGenesectType(u16 item);

/**
 *  @brief get genesect form from held item
 *
 *  @param item held item
 *  @return form from held item
 */
u32 __attribute__((long_call)) GetGenesectForme(u16 item);

/**
 *  @brief handle form change for arceus and genesect in the box when changing held item
 *
 *  @param bp struct BoxPokemon whose form to update
 */
void __attribute__((long_call)) ArceusBoxPokemonFormeChange(struct BoxPokemon *bp);

/**
 *  @brief extension of ArceusBoxPokemonFormeChange to account for giratina as well
 *
 *  @see ArceusBoxPokemonFormeChange
 *  @param bp struct BoxPokemon whose form to update
 *  @return TRUE if form needs updating; FALSE otherwise
 */
BOOL __attribute__((long_call)) HandleBoxPokemonFormeChanges(struct BoxPokemon* bp);

/**
 *  @brief check if a reveal glass can be used on a PartyPokemon
 *
 *  @param pp PartyPokemon to check reveal glass against
 *  @return TRUE if reveal glass can be used; FALSE otherwise
 */
BOOL __attribute__((long_call)) CanUseRevealGlass(struct PartyPokemon *pp);

/**
 *  @brief check if DNA splicers can be used, return position in party if so
 *
 *  @param pp PartyPokemon to check for
 *  @param party Party to search through for matching DNA splicers pokémon
 *  @return party position of pokémon that can be stored by the DNA splicers or'd with RESHIRAM_MASK if reshiram is the first pokémon found
 */
u32 __attribute__((long_call)) CanUseDNASplicersGrabSplicerPos(struct PartyPokemon *pp, struct Party *party);

/**
 *  @brief see if an item changes form or not
 *
 *  @param wk work structure
 *  @param dat data structure
 */
u32 __attribute__((long_call)) UseItemFormeChangeCheck(struct PLIST_WORK *wk, void *dat);

/**
 *  @brief modify PokeListProc_End to increase party size so that when Reshiram/Zekrom are added back from DNA Splicers there are no crashes
 *
 *  @param proc work structure
 *  @param seq step in PokeListProc_End sequence
 */
u32 __attribute__((long_call)) PokeListProc_End_Extend(void *proc, int *seq);

/**
 *  @brief change a PartyPokemon to form, recalculating stats and ability
 *
 *  @param pp PartyPokemon whose form to change
 *  @param form form number
 */
void __attribute__((long_call)) ChangePartyPokemonToForm(struct PartyPokemon *pp, u32 form);

/**
 *  @brief swap out oldMove with newMove in a PartyPokemon's learnset (if it exists)
 *
 *  @param pp PartyPokemon whose move to swap
 *  @param oldMove move to be replaced
 *  @param newMove move that will be written
 */
void __attribute__((long_call)) SwapPartyPokemonMove(struct PartyPokemon *pp, u32 oldMove, u32 newMove);

/**
 *  @brief combine ChangePartyPokemonToForm and SwapPartyPokemonMove
 *
 *  @see ChangePartyPokemonToForm
 *  @see SwapPartyPokemonMove
 */
void __attribute__((long_call)) ChangePartyPokemonToFormSwapMove(struct PartyPokemon *pp, u32 form, u32 oldMove, u32 newMove);

/**
 *  @brief grab current season from the RTC settings
 *
 *  @return current season
 */
u32 __attribute__((long_call)) GrabCurrentSeason(void);

/**
 *  @brief update passive forms (gender and deerling seasons)
 *
 *  @param pp PartyPokemon whose form to update (if applicable)
 */
void __attribute__((long_call)) UpdatePassiveForms(struct PartyPokemon *pp);

/**
 *  @brief run through a party and update all of the deerling forms if present
 *
 *  @param party Party to run through to check for deerling
 */
BOOL __attribute__((long_call)) Party_UpdateDeerlingSeasonForm(struct Party *party);

//BOOL __attribute__((long_call)) Party_TryResetShaymin(struct Party *party, int min_max, const struct RTCTime *time);

/**
 *  @brief load egg moves to dest and return amount of egg moves
 *
 *  @param pokemon PartyPokemon to grab egg moves for
 *  @param dest destination for the array of egg moves
 *  @return number of egg moves in dest
 */
u8 __attribute__((long_call)) LoadEggMoves(struct PartyPokemon *pokemon, u16 *dest);

/**
 *  @brief check if 2 PartyPokemon are essentially the same PartyPokemon beyond duplication/RNG manipulation
 *         checks species, pid, ot id, raw stats, and iv's
 *
 *  @param pokemon1 first PartyPokemon to compare
 *  @param pokemon2 second PartyPokemon to compare
 *  @return TRUE if the PartyPokemon are identical
 */
u32 __attribute__((long_call)) CheckIfMonsAreEqual(struct PartyPokemon *pokemon1, struct PartyPokemon *pokemon2);

/**
 *  @brief get the evolution species for a pokemon.  generalized depending on context
 *         also set form depending on the evolution structure read from armips/data/evodata.s
 *
 *  @param party Party to check through for remoraid and such
 *  @param pokemon PartyPokemon to potentially evolve
 *  @param context EVOCTX_* constant deciding which evolution methods to check
 *  @param usedItem item used on the PartyPokemon, if applicable
 *  @param method_ret pointer to an integer to store the evolution method that was used to evolve
 *  @return the target species to evolev into
 */
u16 __attribute__((long_call)) GetMonEvolution(struct Party *party, struct PartyPokemon *pokemon, u8 context, u16 usedItem, int *method_ret);

/**
 *  @brief grab the sex given species, pid, and form
 *
 *  @param species species id
 *  @param pid personality id
 *  @param form form number
 *  @return POKEMON_GENDER_* constant describing which gender the pokémon is
 */
u32 __attribute__((long_call)) GrabSexFromSpeciesAndForm(u32 species, u32 pid, u32 form);

/**
 *  @brief get the sex of a BoxPokemon
 *
 *  @param bp BoxPokemon whose sex to get
 *  @return sex of passed BoxPokemon as POKEMON_GENDER_* constant
 */
u32 __attribute__((long_call)) GetBoxMonSex(struct BoxPokemon *bp);

/**
 *  @brief get the pokémon overworld tag from species, form, and gender
 *
 *  @param species species index
 *  @param form form number
 *  @param isFemale TRUE if female; FALSE otherwise
 *  @return .tag entry in gOWTagToFileNum
 */
u16 __attribute__((long_call)) get_mon_ow_tag(u16 species, u32 form, u32 isFemale);

/**
 *  @brief give a PartyPokemon to the player given species, level, form, ability, etc.
 *
 *  @param heapId heap to use for memory here
 *  @param saveData saveData as gotten from SaveBlock2_get()
 *  @param species species index
 *  @param level level of the given PartyPokemon
 *  @param forme form number
 *  @param ability ability index
 *  @param heldItem held item index
 *  @param ball ball id
 *  @param encounterType encounter type
 *  @return TRUE if successful; FALSE otherwise
 */
BOOL __attribute__((long_call)) GiveMon(int heapId, void *saveData, int species, int level, int forme, u8 ability, u16 heldItem, int ball, int encounterType);

//BOOL __attribute__((long_call)) AddWildPartyPokemon(int inTarget, EncounterInfo *encounterInfo, struct PartyPokemon *encounterPartyPokemon, struct BATTLE_PARAM *encounterBattleParam);

/**
 *  @brief create BoxPokemon given the parameters
 *
 *  @param boxmon BoxPokemon to fill out
 *  @param species species index
 *  @param level level the BoxPokemon should be set at
 *  @param pow iv to set flat across the board; else set randomly
 *  @param rndflag if TRUE, use rnd for the personality id
 *  @param rnd if rndflag is TRUE, personality id
 *  @param idflag if TRUE, use id for original trainer id
 *  @param id if idflag is TRUE, original trainer id
 */
void __attribute__((long_call)) CreateBoxMonData(struct BoxPokemon *boxmon, int species, int level, int pow, int rndflag, u32 rnd, int idflag, u32 id);

/**
 *  @brief revert a form change at the end of a battle
 *
 *  @param pp PartyPokemon whose form to potentially revert
 *  @param species species index
 *  @param form_no form number
 *  @return TRUE if form was reverted; FALSE otherwise
 */
bool8 __attribute__((long_call)) RevertFormChange(struct PartyPokemon *pp, u16 species, u8 form_no);

/**
 *  @brief clear a PartyPokemon's moves by setting them to zero
 *
 *  @param pokemon PartyPokemon whose moves to clear
 */
void __attribute__((long_call)) ClearMonMoves(struct PartyPokemon *pokemon);

// defined in src/moves.c--can't just define in battles, sadly.  does need BattleMove structure from battle.h, though
/**
 *  @brief get move data field requested from ARC_MOVE_DATA
 *
 *  @param id move index
 *  @param field MOVE_DATA_* constant requesting data
 *  @return requested data
 */
u32 __attribute__((long_call)) GetMoveData(u16 id, u32 field);


#endif
