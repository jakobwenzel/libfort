#include "fort_utils.h"
#include <assert.h>
#include "properties.h"
#include "vector.h"

#define FT_RESET_COLOR "\033[0m"

const char *fg_colors[] = {
    "",
    "\033[30m",
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m",
    "\033[37m",
    "\033[90m",
    "\033[91m",
    "\033[92m",
    "\033[93m",
    "\033[94m",
    "\033[95m",
    "\033[96m",
    "\033[97m",
};

const char *reset_fg_colors[] = {
    "",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
    "\033[39m",
};

const char *bg_colors[] = {
    "",
    "\033[40m",
    "\033[41m",
    "\033[42m",
    "\033[43m",
    "\033[44m",
    "\033[45m",
    "\033[46m",
    "\033[47m",
    "\033[100m",
    "\033[101m",
    "\033[102m",
    "\033[103m",
    "\033[104m",
    "\033[105m",
    "\033[106m",
    "\033[107m",
};

const char *reset_bg_colors[] = {
    "",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
    "\033[49m",
};


const char *text_styles[] = {
    "",
    "\033[1m",
    "\033[2m",
    "\033[3m",
    "\033[4m",
    "\033[5m",
    "\033[7m",
    "\033[8m",
};

const char *reset_text_styles[] = {
    "",
    "\033[21m",
    "\033[22m",
    "\033[23m",
    "\033[24m",
    "\033[25m",
    "\033[27m",
    "\033[28m",
};


static const size_t n_fg_colors = sizeof(fg_colors) / sizeof(fg_colors[0]);
static const size_t n_bg_colors = sizeof(bg_colors) / sizeof(bg_colors[0]);
static const size_t n_styles = sizeof(text_styles) / sizeof(text_styles[0]);

void get_style_tag_for_cell(const fort_table_properties_t *props,
                            size_t row, size_t col, char *style_tag, size_t sz)
{
    (void)sz;

    unsigned bg_color_number = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CELL_BG_COLOR);
    unsigned text_style = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CELL_TEXT_STYLE);

    style_tag[0] = '\0';

    if (text_style < n_styles) {
        strcat(style_tag, text_styles[text_style]);
    } else {
        goto error;
    }

    if (bg_color_number < n_bg_colors) {
        strcat(style_tag, bg_colors[bg_color_number]);
    } else {
        goto error;
    }

    return;

error:
    // shouldn't be here
    assert(0);
    style_tag[0] = '\0';
    return;
}

void get_reset_style_tag_for_cell(const fort_table_properties_t *props,
                                  size_t row, size_t col, char *reset_style_tag, size_t sz)
{
    (void)sz;

    unsigned bg_color_number = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CELL_BG_COLOR);
    unsigned text_style = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CELL_TEXT_STYLE);

    reset_style_tag[0] = '\0';

    if (text_style < n_styles) {
        strcat(reset_style_tag, reset_text_styles[text_style]);
    } else {
        goto error;
    }

    if (bg_color_number < n_bg_colors) {
        strcat(reset_style_tag, reset_bg_colors[bg_color_number]);
    } else {
        goto error;
    }

    return;

error:
    // shouldn't be here
    assert(0);
    reset_style_tag[0] = '\0';
    return;
}


void get_style_tag_for_content(const fort_table_properties_t *props,
                               size_t row, size_t col, char *style_tag, size_t sz)
{
    (void)sz;

    unsigned text_style = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CONT_TEXT_STYLE);
    unsigned fg_color_number = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CONT_FG_COLOR);
    unsigned bg_color_number = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CONT_BG_COLOR);

    style_tag[0] = '\0';

    if (text_style < n_styles) {
        strcat(style_tag, text_styles[text_style]);
    } else {
        goto error;
    }

    if (fg_color_number < n_fg_colors) {
        strcat(style_tag, fg_colors[fg_color_number]);
    } else {
        goto error;
    }

    if (bg_color_number < n_bg_colors) {
        strcat(style_tag, bg_colors[bg_color_number]);
    } else {
        goto error;
    }

    return;

error:
    // shouldn't be here
    assert(0);
    style_tag[0] = '\0';
    return;
}

void get_reset_style_tag_for_content(const fort_table_properties_t *props,
                                     size_t row, size_t col, char *reset_style_tag, size_t sz)
{
    (void)sz;

    unsigned text_style = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CONT_TEXT_STYLE);
    unsigned fg_color_number = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CONT_FG_COLOR);
    unsigned bg_color_number = get_cell_property_value_hierarcial(props, row, col, FT_CPROP_CONT_BG_COLOR);

    reset_style_tag[0] = '\0';

    if (text_style < n_styles) {
        strcat(reset_style_tag, reset_text_styles[text_style]);
    } else {
        goto error;
    }

    if (fg_color_number < n_fg_colors) {
        strcat(reset_style_tag, reset_fg_colors[fg_color_number]);
    } else {
        goto error;
    }

    if (bg_color_number < n_bg_colors) {
        strcat(reset_style_tag, reset_bg_colors[bg_color_number]);
    } else {
        goto error;
    }

    return;

error:
    // shouldn't be here
    assert(0);
    reset_style_tag[0] = '\0';
    return;
}

/*****************************************************************************
 *               COLUMN PROPERTIES
 * ***************************************************************************/

struct fort_cell_props g_default_cell_properties = {
    FT_ANY_ROW,    /* cell_row */
    FT_ANY_COLUMN, /* cell_col */

    /* properties */
    FT_CPROP_MIN_WIDTH  | FT_CPROP_TEXT_ALIGN | FT_CPROP_TOP_PADDING
    | FT_CPROP_BOTTOM_PADDING | FT_CPROP_LEFT_PADDING | FT_CPROP_RIGHT_PADDING
    | FT_CPROP_EMPTY_STR_HEIGHT | FT_CPROP_CONT_FG_COLOR | FT_CPROP_CELL_BG_COLOR
    | FT_CPROP_CONT_BG_COLOR | FT_CPROP_CELL_TEXT_STYLE | FT_CPROP_CONT_TEXT_STYLE,

    0,             /* col_min_width */
    FT_ALIGNED_LEFT,  /* align */
    0,      /* cell_padding_top         */
    0,      /* cell_padding_bottom      */
    1,      /* cell_padding_left        */
    1,      /* cell_padding_right       */
    1,      /* cell_empty_string_height */

    FT_ROW_COMMON, /* row_type */
    FT_COLOR_DEFAULT, /* content_fg_color_number */
    FT_COLOR_DEFAULT, /* content_bg_color_number */
    FT_COLOR_DEFAULT, /* cell_bg_color_number */
    FT_TSTYLE_DEFAULT, /* cell_text_style */
    FT_TSTYLE_DEFAULT, /* content_text_style */
};

static int get_prop_value_if_exists_otherwise_default(const struct fort_cell_props *cell_opts, uint32_t property)
{
    if (cell_opts == NULL || !PROP_IS_SET(cell_opts->properties, property)) {
        cell_opts = &g_default_cell_properties;
    }

    switch (property) {
        case FT_CPROP_MIN_WIDTH:
            return cell_opts->col_min_width;
        case FT_CPROP_TEXT_ALIGN:
            return cell_opts->align;
        case FT_CPROP_TOP_PADDING:
            return cell_opts->cell_padding_top;
        case FT_CPROP_BOTTOM_PADDING:
            return cell_opts->cell_padding_bottom;
        case FT_CPROP_LEFT_PADDING:
            return cell_opts->cell_padding_left;
        case FT_CPROP_RIGHT_PADDING:
            return cell_opts->cell_padding_right;
        case FT_CPROP_EMPTY_STR_HEIGHT:
            return cell_opts->cell_empty_string_height;
        case FT_CPROP_ROW_TYPE:
            return cell_opts->row_type;
        case FT_CPROP_CONT_FG_COLOR:
            return cell_opts->content_fg_color_number;
        case FT_CPROP_CONT_BG_COLOR:
            return cell_opts->content_bg_color_number;
        case FT_CPROP_CELL_BG_COLOR:
            return cell_opts->cell_bg_color_number;
        case FT_CPROP_CELL_TEXT_STYLE:
            return cell_opts->cell_text_style;
        case FT_CPROP_CONT_TEXT_STYLE:
            return cell_opts->content_text_style;
        default:
            /* todo: implement later */
            exit(333);
    }
}


FT_INTERNAL
fort_cell_prop_container_t *create_cell_prop_container(void)
{
    fort_cell_prop_container_t *ret = create_vector(sizeof(fort_cell_props_t), DEFAULT_VECTOR_CAPACITY);
    return ret;
}


FT_INTERNAL
void destroy_cell_prop_container(fort_cell_prop_container_t *cont)
{
    if (cont)
        destroy_vector(cont);
}


FT_INTERNAL
const fort_cell_props_t *cget_cell_prop(const fort_cell_prop_container_t *cont, size_t row, size_t col)
{
    assert(cont);
    size_t sz = vector_size(cont);
    size_t i = 0;
    for (i = 0; i < sz; ++i) {
        const fort_cell_props_t *opt = (const fort_cell_props_t *)vector_at_c(cont, i);
        if (opt->cell_row == row && opt->cell_col == col)
            return opt;
    }
    return NULL;
}


FT_INTERNAL
fort_cell_props_t *get_cell_prop_and_create_if_not_exists(fort_cell_prop_container_t *cont, size_t row, size_t col)
{
    assert(cont);
    size_t sz = vector_size(cont);
    size_t i = 0;
    for (i = 0; i < sz; ++i) {
        fort_cell_props_t *opt = (fort_cell_props_t *)vector_at(cont, i);
        if (opt->cell_row == row && opt->cell_col == col)
            return opt;
    }

    fort_cell_props_t opt;
    if (row == FT_ANY_ROW && col == FT_ANY_COLUMN)
        memcpy(&opt, &g_default_cell_properties, sizeof(fort_cell_props_t));
    else
        memset(&opt, 0, sizeof(fort_cell_props_t));

    opt.cell_row = row;
    opt.cell_col = col;
    if (FT_IS_SUCCESS(vector_push(cont, &opt))) {
        return (fort_cell_props_t *)vector_at(cont, sz);
    }

    return NULL;
}


FT_INTERNAL
int get_cell_property_value_hierarcial(const fort_table_properties_t *propertiess, size_t row, size_t column, uint32_t property)
{
    assert(propertiess);
    size_t row_origin = row;

    const fort_cell_props_t *opt = NULL;
    if (propertiess->cell_properties != NULL) {
        while (1) {
            opt = cget_cell_prop(propertiess->cell_properties, row, column);
            if (opt != NULL && PROP_IS_SET(opt->properties, property))
                break;

            if (row != FT_ANY_ROW && column != FT_ANY_COLUMN) {
                row = FT_ANY_ROW;
                continue;
            } else if (row == FT_ANY_ROW && column != FT_ANY_COLUMN) {
                row = row_origin;
                column = FT_ANY_COLUMN;
                continue;
            } else if (row != FT_ANY_ROW  && column == FT_ANY_COLUMN) {
                row = FT_ANY_ROW;
                column = FT_ANY_COLUMN;
                continue;
            }

//            if (row != FT_ANY_ROW) {
//                row = FT_ANY_ROW;
//                continue;
//            }
//            if (column != FT_ANY_COLUMN) {
//                column = FT_ANY_COLUMN;
//                continue;
//            }

            opt = NULL;
            break;
        }
    }

    return get_prop_value_if_exists_otherwise_default(opt, property);
}


static fort_status_t set_cell_property_impl(fort_cell_props_t *opt, uint32_t property, int value)
{
    assert(opt);

    PROP_SET(opt->properties, property);
    if (PROP_IS_SET(property, FT_CPROP_MIN_WIDTH)) {
        CHECK_NOT_NEGATIVE(value);
        opt->col_min_width = value;
    } else if (PROP_IS_SET(property, FT_CPROP_TEXT_ALIGN)) {
        opt->align = (enum ft_text_alignment)value;
    } else if (PROP_IS_SET(property, FT_CPROP_TOP_PADDING)) {
        CHECK_NOT_NEGATIVE(value);
        opt->cell_padding_top = value;
    } else if (PROP_IS_SET(property, FT_CPROP_BOTTOM_PADDING)) {
        CHECK_NOT_NEGATIVE(value);
        opt->cell_padding_bottom = value;
    } else if (PROP_IS_SET(property, FT_CPROP_LEFT_PADDING)) {
        CHECK_NOT_NEGATIVE(value);
        opt->cell_padding_left = value;
    } else if (PROP_IS_SET(property, FT_CPROP_RIGHT_PADDING)) {
        CHECK_NOT_NEGATIVE(value);
        opt->cell_padding_right = value;
    } else if (PROP_IS_SET(property, FT_CPROP_EMPTY_STR_HEIGHT)) {
        CHECK_NOT_NEGATIVE(value);
        opt->cell_empty_string_height = value;
    } else if (PROP_IS_SET(property, FT_CPROP_ROW_TYPE)) {
        opt->row_type = (enum ft_row_type)value;
    } else if (PROP_IS_SET(property, FT_CPROP_CONT_FG_COLOR)) {
        opt->content_fg_color_number = value;
    } else if (PROP_IS_SET(property, FT_CPROP_CONT_BG_COLOR)) {
        opt->content_bg_color_number = value;
    } else if (PROP_IS_SET(property, FT_CPROP_CELL_BG_COLOR)) {
        opt->cell_bg_color_number = value;
    } else if (PROP_IS_SET(property, FT_CPROP_CELL_TEXT_STYLE)) {
        opt->cell_text_style = value;
    } else if (PROP_IS_SET(property, FT_CPROP_CONT_TEXT_STYLE)) {
        opt->content_text_style = value;
    }

    return FT_SUCCESS;

fort_fail:
    return FT_EINVAL;
}


FT_INTERNAL
fort_status_t set_cell_property(fort_cell_prop_container_t *cont, size_t row, size_t col, uint32_t property, int value)
{
    fort_cell_props_t *opt = get_cell_prop_and_create_if_not_exists(cont, row, col);
    if (opt == NULL)
        return FT_ERROR;

    return set_cell_property_impl(opt, property, value);
    /*
    PROP_SET(opt->propertiess, property);
    if (PROP_IS_SET(property, FT_CPROP_MIN_WIDTH)) {
        opt->col_min_width = value;
    } else if (PROP_IS_SET(property, FT_CPROP_TEXT_ALIGN)) {
        opt->align = value;
    }

    return FT_SUCCESS;
    */
}


FT_INTERNAL
fort_status_t set_default_cell_property(uint32_t property, int value)
{
    return set_cell_property_impl(&g_default_cell_properties, property, value);
}

/*****************************************************************************
 *               PROPERTIESS
 * ***************************************************************************/


#define BASIC_STYLE  {            \
    /* border_chars */            \
    {                             \
     "+", "-", "+", "+",          \
     "|", "|", "|",               \
     "\0", "\0", "\0", "\0",      \
     "+", "-", "+", "+",          \
     "+", "+", "+", "+",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    "+", "-", "+", "+",           \
    "|", "|", "|",                \
    "+", "-", "+", "+",           \
    "+", "-", "+", "+",           \
    "+", "+", "+", "+",           \
    },                            \
    /* separator_chars */         \
    {                             \
    "+", "-", "+", "+",           \
    "+", "+",                     \
    },                            \
}

#define BASIC2_STYLE  {           \
    /* border_chars */            \
    {                             \
     "+", "-", "+", "+",          \
     "|", "|", "|",               \
     "+", "-", "+", "+",          \
     "+", "-", "+", "+",          \
     "+", "+", "+", "+",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    "+", "-", "+", "+",           \
    "|", "|", "|",                \
    "+", "-", "+", "+",           \
    "+", "-", "+", "+",           \
    "+", "+", "+", "+",           \
    },                            \
    /* separator_chars */         \
    {                             \
    "+", "-", "+", "+",           \
    "+", "+",                     \
    },                            \
}

#define SIMPLE_STYLE  {           \
    /* border_chars */            \
    {                             \
     " ", " ", " ", " ",          \
     " ", " ", " ",               \
     "\0", "\0", "\0", "\0",      \
     " ", " ", " ", " ",          \
     " ", " ", " ", " ",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    " ", " ", " ", " ",           \
    " ", " ", " ",                \
    " ", "-", " ", " ",           \
    " ", " ", " ", " ",           \
    " ", "-", " ", "-",           \
    },                            \
    /* separator_chars */         \
    {                             \
    " ", "-", " ", " ",           \
    " ", " ",                     \
    },                            \
}

#define PLAIN_STYLE  {            \
    /* border_chars */            \
    {                             \
     " ", " ", " ", " ",          \
     " ", " ", " ",               \
     "\0", "\0", "\0", "\0",      \
     " ", " ", " ", " ",          \
     " ", " ", " ", " ",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    " ", "-", "-", " ",           \
    " ", " ", " ",                \
    " ", "-", "-", " ",           \
    " ", "-", "-", " ",           \
    " ", "-", " ", "-",           \
    },                            \
    /* separator_chars */         \
    {                             \
    " ", "-", "-", " ",           \
    "-", "-",                     \
    },                            \
}

#define DOT_STYLE  {              \
    /* border_chars */            \
    {                             \
     ".", ".", ".", ".",          \
     ":", ":", ":",               \
     "\0", "\0", "\0", "\0",      \
     ":", ".", ":", ":",          \
     "+", ":", "+", ":",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    ".", ".", ".", ".",           \
    ":", ":", ":",                \
    ":", ".", ":", ":",           \
    ":", ".", ":", ":",           \
    "+", ".", "+", ".",           \
    },                            \
    /* separator_chars */         \
    {                             \
    ":", ".", ":", ":",           \
    ":", ":",                     \
    },                            \
}

#define EMPTY_STYLE  {            \
    /* border_chars */            \
    {                             \
     " ", " ", " ", " ",          \
     " ", " ", " ",               \
     "\0", "\0", "\0", "\0",      \
     " ", " ", " ", " ",          \
     " ", " ", " ", " ",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    " ", " ", " ", " ",           \
    " ", " ", " ",                \
    "\0", "\0", "\0", "\0",       \
    " ", " ", " ", " ",           \
    " ", " ", " ", " ",           \
    },                            \
    /* separator_chars */         \
    {                             \
    " ", " ", " ", " ",           \
    " ", " ",                     \
    },                            \
}


#define SOLID_STYLE  {            \
    /* border_chars */            \
    {                             \
     "┌", "─", "┬", "┐",          \
     "│", "│", "│",               \
     "", "", "", "",              \
     "└", "─", "┴", "╯",          \
     "│", "─", "│", "─",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    "┌", "─", "┬", "┐",           \
    "│", "│", "│",                \
    "├", "─", "┼", "┤",           \
    "└", "─", "┴", "┘",           \
    "┼", "┬", "┼", "┴",           \
    },                            \
    /* separator_chars */         \
    {                             \
    "├", "─", "┼", "┤",           \
    "┬", "┴",                     \
    },                            \
}

#define SOLID_ROUND_STYLE  {      \
    /* border_chars */            \
    {                             \
     "╭", "─", "┬", "╮",          \
     "│", "│", "│",               \
     "", "", "", "",              \
     "╰", "─", "┴", "╯",          \
     "│", "─", "│", "─",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    "╭", "─", "┬", "╮",           \
    "│", "│", "│",                \
    "├", "─", "┼", "┤",           \
    "╰", "─", "┴", "╯",           \
    "┼", "┬", "┼", "┴",           \
    },                            \
    /* separator_chars */         \
    {                             \
    "├", "─", "┼", "┤",           \
    "┬", "┴",                     \
    },                            \
}


#define DOUBLE_STYLE  {           \
    /* border_chars */            \
    {                             \
     "╔", "═", "╦", "╗",          \
     "║", "║", "║",               \
     "", "", "", "",              \
     "╚", "═", "╩", "╝",          \
     "┣", "┻", "┣", "┳",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    "╔", "═", "╦", "╗",           \
    "║", "║", "║",                \
    "╠", "═", "╬", "╣",           \
    "╚", "═", "╩", "╝",           \
    "┣", "╦", "┣", "╩",           \
    },                            \
    /* separator_chars */         \
    {                             \
    "╠", "═", "╬", "╣",           \
    "╦", "╩",                     \
    },                            \
}


#define DOUBLE2_STYLE  {          \
    /* border_chars */            \
    {                             \
     "╔", "═", "╤", "╗",          \
     "║", "│", "║",               \
     "╟", "─", "┼", "╢",          \
     "╚", "═", "╧", "╝",          \
     "├", "┬", "┤", "┴",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    "╔", "═", "╤", "╗",           \
    "║", "│", "║",                \
    "╠", "═", "╪", "╣",           \
    "╚", "═", "╧", "╝",           \
    "├", "╤", "┤", "╧",           \
    },                            \
    /* separator_chars */         \
    {                             \
    "╠", "═", "╪", "╣",           \
    "╤", "╧",                     \
    },                            \
}


#define BOLD_STYLE  {             \
    /* border_chars */            \
    {                             \
     "┏", "━", "┳", "┓",          \
     "┃", "┃", "┃",               \
     "", "", "", "",              \
     "┗", "━", "┻", "┛",          \
     "┣", "┻", "┣", "┳",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    "┏", "━", "┳", "┓",           \
    "┃", "┃", "┃",                \
    "┣", "━", "╋", "┫",           \
    "┗", "━", "┻", "┛",           \
    "┣", "┳", "┣", "┻",           \
    },                            \
    /* separator_chars */         \
    {                             \
    "┣", "━", "╋", "┫",           \
    "┳", "┻",                     \
    },                            \
}

#define BOLD2_STYLE  {            \
    /* border_chars */            \
    {                             \
     "┏", "━", "┯", "┓",          \
     "┃", "│", "┃",               \
     "┠", "─", "┼", "┨",          \
     "┗", "━", "┷", "┛",          \
     "┣", "┬", "┣", "┴",          \
    },                            \
    /* header_border_chars */     \
    {                             \
    "┏", "━", "┯", "┓",           \
    "┃", "│", "┃",                \
    "┣", "━", "┿", "┫",           \
    "┗", "━", "┷", "┛",           \
    "┣", "┯", "┣", "┷",           \
    },                            \
    /* separator_chars */         \
    {                             \
    "┣", "━", "┿", "┫",           \
    "┯", "┷",                     \
    },                            \
}

#define FRAME_STYLE  {             \
    /* border_chars */            \
    {                             \
     "▛", "▀", "▀", "▜",          \
     "▌", "┃", "▐",               \
     "", "", "", "",              \
     "▙", "▄", "▄", "▟",          \
     "┣", "━", "┣", "━"           \
    },                            \
    /* header_border_chars */     \
    {                             \
    "▛", "▀", "▀", "▜",           \
    "▌", "┃", "▐",                \
    "▌", "━", "╋", "▐",           \
    "▙", "▄", "▄", "▟",           \
    "┣", "━", "┣", "━",           \
    },                            \
    /* separator_chars */         \
    {                             \
    "▌", "━", "╋", "▐",           \
    "╋", "╋",                     \
    },                            \
}


struct fort_border_style FORT_BASIC_STYLE = BASIC_STYLE;
struct fort_border_style FORT_BASIC2_STYLE = BASIC2_STYLE;
struct fort_border_style FORT_SIMPLE_STYLE = SIMPLE_STYLE;
struct fort_border_style FORT_PLAIN_STYLE = PLAIN_STYLE;
struct fort_border_style FORT_DOT_STYLE = DOT_STYLE;
struct fort_border_style FORT_EMPTY_STYLE = EMPTY_STYLE;
struct fort_border_style FORT_SOLID_STYLE = SOLID_STYLE;
struct fort_border_style FORT_SOLID_ROUND_STYLE = SOLID_ROUND_STYLE;
struct fort_border_style FORT_DOUBLE_STYLE = DOUBLE_STYLE;
struct fort_border_style FORT_DOUBLE2_STYLE = DOUBLE2_STYLE;
struct fort_border_style FORT_BOLD_STYLE = BOLD_STYLE;
struct fort_border_style FORT_BOLD2_STYLE = BOLD2_STYLE;
struct fort_border_style FORT_FRAME_STYLE = FRAME_STYLE;



fort_entire_table_properties_t g_entire_table_properties = {
    0, /* left_margin */
    0, /* top_margin */
    0, /* right_margin */
    0, /* bottom_margin */
};

static fort_status_t set_entire_table_property_internal(fort_entire_table_properties_t *properties, uint32_t property, int value)
{
    assert(properties);
    CHECK_NOT_NEGATIVE(value);
    if (PROP_IS_SET(property, FT_TPROP_LEFT_MARGIN)) {
        properties->left_margin = value;
    } else if (PROP_IS_SET(property, FT_TPROP_TOP_MARGIN)) {
        properties->top_margin = value;
    } else if (PROP_IS_SET(property, FT_TPROP_RIGHT_MARGIN)) {
        properties->right_margin = value;
    } else if (PROP_IS_SET(property, FT_TPROP_BOTTOM_MARGIN)) {
        properties->bottom_margin = value;
    } else {
        return FT_EINVAL;
    }
    return FT_SUCCESS;

fort_fail:
    return FT_EINVAL;
}


FT_INTERNAL
fort_status_t set_entire_table_property(fort_table_properties_t *table_properties, uint32_t property, int value)
{
    assert(table_properties);
    return set_entire_table_property_internal(&table_properties->entire_table_properties, property, value);
}


FT_INTERNAL
fort_status_t set_default_entire_table_property(uint32_t property, int value)
{
    return set_entire_table_property_internal(&g_entire_table_properties, property, value);
}


FT_INTERNAL
size_t max_border_elem_strlen(struct fort_table_properties *properties)
{
    assert(properties);
    size_t result = 1;
    int i = 0;
    for (i = 0; i < BorderItemPosSize; ++i) {
        result = MAX(result, strlen(properties->border_style.border_chars[i]));
    }

    i = 0;
    for (i = 0; i < BorderItemPosSize; ++i) {
        result = MAX(result, strlen(properties->border_style.header_border_chars[i]));
    }

    i = 0;
    for (i = 0; i < SepratorItemPosSize; ++i) {
        result = MAX(result, strlen(properties->border_style.separator_chars[i]));
    }
    return result;
}


fort_table_properties_t g_table_properties = {
    /* border_style */
    BASIC_STYLE,
    NULL,     /* cell_properties */
    /* entire_table_properties */
    {
        0, /* left_margin */
        0, /* top_margin */
        0, /* right_margin */
        0  /* bottom_margin */
    }
};


FT_INTERNAL
fort_table_properties_t *create_table_properties(void)
{
    fort_table_properties_t *properties = (fort_table_properties_t *)F_CALLOC(sizeof(fort_table_properties_t), 1);
    if (properties == NULL) {
        return NULL;
    }
    memcpy(properties, &g_table_properties, sizeof(fort_table_properties_t));
    properties->cell_properties = create_cell_prop_container();
    if (properties->cell_properties == NULL) {
        destroy_table_properties(properties);
        return NULL;
    }
    memcpy(&properties->entire_table_properties, &g_entire_table_properties, sizeof(fort_entire_table_properties_t));
    return properties;
}

FT_INTERNAL
void destroy_table_properties(fort_table_properties_t *properties)
{
    if (properties == NULL)
        return;

    if (properties->cell_properties != NULL) {
        destroy_cell_prop_container(properties->cell_properties);
    }
    F_FREE(properties);
}

static
fort_cell_prop_container_t *copy_cell_properties(fort_cell_prop_container_t *cont)
{
    fort_cell_prop_container_t *result = create_cell_prop_container();
    if (result == NULL)
        return NULL;

    size_t sz = vector_size(cont);
    for (size_t i = 0; i < sz; ++i) {
        fort_cell_props_t *opt = (fort_cell_props_t *)vector_at(cont, i);
        if (FT_IS_ERROR(vector_push(result, opt))) {
            destroy_cell_prop_container(result);
            return NULL;
        }
    }
    return result;
}

FT_INTERNAL
fort_table_properties_t *copy_table_properties(const fort_table_properties_t *properties)
{
    fort_table_properties_t *new_opt = create_table_properties();
    if (new_opt == NULL)
        return NULL;

    destroy_vector(new_opt->cell_properties);
    new_opt->cell_properties = copy_cell_properties(properties->cell_properties);
    if (new_opt == NULL) {
        destroy_table_properties(new_opt);
        return NULL;
    }

    memcpy(&new_opt->border_style, &properties->border_style, sizeof(struct fort_border_style));
    memcpy(&new_opt->entire_table_properties,
           &properties->entire_table_properties, sizeof(fort_entire_table_properties_t));

    return new_opt;
}



