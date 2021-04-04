/**
 * Copyright 2018 Slawomir Maludzinski
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "param.h"
#include "dim.h"
#include "range.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

param * param_new_bool(char * id)
{
    param * value = (param *)malloc(sizeof(param));
    
    value->type = PARAM_BOOL;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->params = NULL;
    value->ret = NULL;
    value->line_no = 0;
    
    return value;
}

param * param_new_int(char * id)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_INT;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->params = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_long(char * id)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_LONG;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->params = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_float(char * id)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_FLOAT;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->params = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_double(char * id)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_DOUBLE;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->params = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_char(char * id)
{
    param * value = (param *)malloc(sizeof(param));
    
    value->type = PARAM_CHAR;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->params = NULL;
    value->ret = NULL;
    value->line_no = 0;
    
    return value;
}

param * param_new_string(char * id)
{
    param * value = (param *)malloc(sizeof(param));
    
    value->type = PARAM_STRING;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->params = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_void(char * id)
{
    param * value = (param *)malloc(sizeof(param));
    
    value->type = PARAM_VOID;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = NULL;
    value->params = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_c_ptr(char * id)
{
    param * value = (param *)malloc(sizeof(param));
    
    value->type = PARAM_C_PTR;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->params = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_dim(char * id)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_DIM;
    value->const_type = PARAM_CONST_TYPE_CONST;
    value->index = -1;
    value->id = id;
    value->array = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_array(char * id, param_list * dims, param * ret)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_ARRAY;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->dims = dims;
    value->ret = ret;
    value->line_no = 0;

    if (dims != NULL)
    {
        param_dim_set_array(dims, value);
    }

    return value;
}

param * param_new_range(char * id, range_list * ranges)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_RANGE;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->ranges = ranges;
    value->line_no = 0;

    value->ret = param_new_int(NULL);

    if (value->ranges != NULL)
    {
        range_dim_set_range(value->ranges, value);
    }

    return value;
}

param * param_new_range_dim(char * id)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_RANGE_DIM;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_slice(char * id, range_list * ranges, param * ret)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_SLICE;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->ranges = ranges;
    value->ret = ret;
    value->line_no = 0;

    if (value->ranges != NULL)
    {
        range_dim_set_slice(value->ranges, value);
    }

    return value;
}

param * param_new_record(char * id, char * record_id)
{
    param * value = (param *)malloc(sizeof(param));
    
    value->type = PARAM_RECORD;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->record_id = record_id;
    value->module_id = NULL;
    value->record_value = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_record_module(char * id, char * record_id, char * module_id)
{
    param * value = (param *)malloc(sizeof(param));
    
    value->type = PARAM_RECORD;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->record_id = record_id;
    value->module_id = module_id;
    value->record_value = NULL;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

param * param_new_func(char * id, param_list * params, param * ret)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_FUNC;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->index = -1;
    value->id = id;
    value->params = params;
    value->ret = ret;
    value->line_no = 0;

    return value;
}

param * param_new_touple(char * id, param_list * dims)
{
    param * value = (param *)malloc(sizeof(param));

    value->type = PARAM_TOUPLE;
    value->const_type = PARAM_CONST_TYPE_UNKNOWN;
    value->id = id;
    value->dims = dims;
    value->ret = NULL;
    value->line_no = 0;

    return value;
}

void param_delete(param * value)
{
    if (value->id)
    {
        free(value->id);
    }

    switch (value->type)
    {
        case PARAM_BOOL:
        case PARAM_INT:
        case PARAM_LONG:
        case PARAM_FLOAT:
        case PARAM_DOUBLE:
        case PARAM_CHAR:
        case PARAM_STRING:
        case PARAM_VOID:
        case PARAM_C_PTR:
        case PARAM_DIM:
        case PARAM_RANGE_DIM:
        case PARAM_SLICE_DIM:
        break;
        case PARAM_ARRAY:
            if (value->dims != NULL)
            {
                param_list_delete(value->dims);
            }
        break;
        case PARAM_RANGE:
        case PARAM_SLICE:
            if (value->ranges != NULL)
            {
                range_list_delete(value->ranges);
            }
        break;
        case PARAM_ENUMTYPE:
        case PARAM_RECORD:
            if (value->record_id)
            {
                free(value->record_id);
            }
            if (value->module_id)
            {
                free(value->module_id);
            }
        break;
        case PARAM_FUNC:
            if (value->params != NULL)
            {
                param_list_delete(value->params);
            }
        break;
        case PARAM_TOUPLE:
            if (value->dims != NULL)
            {
                param_list_delete(value->dims);
            }
        break;
    }

    if (value->ret)
    {
        param_delete(value->ret);
    }

    free(value);
}

int param_cmp(param * param_one, param * param_two, bool const_cmp)
{
    if (param_one == NULL && param_two == NULL)
    {
        return PARAM_CMP_SUCC;
    }
    if ((param_one == NULL && param_two != NULL) ||
        (param_one != NULL && param_two == NULL))
    {
        return PARAM_CMP_FAIL;
    }
    if (const_cmp &&
        param_one->const_type != param_two->const_type)
    {
        return PARAM_CMP_FAIL;
    }
    if (param_one->type == PARAM_BOOL && param_two->type == PARAM_BOOL)
    {
        return PARAM_CMP_SUCC;
    }
    else if (param_one->type == PARAM_INT && param_two->type == PARAM_INT)
    {
        return PARAM_CMP_SUCC;
    }
    else if (param_one->type == PARAM_FLOAT && param_two->type == PARAM_FLOAT)
    {
        return PARAM_CMP_SUCC;
    }
    else if (param_one->type == PARAM_CHAR && param_two->type == PARAM_CHAR)
    {
        return PARAM_CMP_SUCC;
    }
    else if (param_one->type == PARAM_STRING && param_two->type == PARAM_STRING)
    {
        return PARAM_CMP_SUCC;
    }
    else if (param_one->type == PARAM_VOID && param_two->type == PARAM_VOID)
    {
        return PARAM_CMP_SUCC;
    }
    else if (param_one->type == PARAM_C_PTR && param_two->type == PARAM_C_PTR)
    {
        return PARAM_CMP_SUCC;
    }
    else if (param_one->type == PARAM_ARRAY && param_two->type == PARAM_ARRAY)
    {
        if ((param_one->dims->count == param_two->dims->count) &&
            (param_cmp(param_one->ret, param_two->ret, false) == PARAM_CMP_SUCC))
        {
            return PARAM_CMP_SUCC;
        }
        else
        {
            return PARAM_CMP_FAIL;
        }
    }
    else if (param_one->type == PARAM_RANGE && param_two->type == PARAM_RANGE)
    {
        if (param_one->ranges->count == param_two->ranges->count)        
        {
            return PARAM_CMP_SUCC;
        }
        else
        {
            return PARAM_CMP_FAIL;
        }
    }
    else if (param_one->type == PARAM_RANGE_DIM && param_two->type == PARAM_RANGE_DIM)
    {
        return PARAM_CMP_SUCC;
    }
    else if (param_one->type == PARAM_SLICE && param_two->type == PARAM_SLICE)
    {
        if ((param_one->ranges->count == param_two->ranges->count) &&
            (param_cmp(param_one->ret, param_two->ret, false) == PARAM_CMP_SUCC))
        {
            return PARAM_CMP_SUCC;
        }
        else
        {
            return PARAM_CMP_FAIL;
        }
    }
    else if (param_one->type == PARAM_ENUMTYPE && param_two->type == PARAM_ENUMTYPE)
    {
        if (param_one->enumtype_value == param_two->enumtype_value)
        {
            return PARAM_CMP_SUCC;
        }
        else
        {
            return PARAM_CMP_FAIL;
        }
    }
    else if (param_one->type == PARAM_RECORD && param_two->type == PARAM_RECORD)
    {
         if (param_one->record_value == param_two->record_value)
         {
             return PARAM_CMP_SUCC;
         }
         else
         {
             return PARAM_CMP_FAIL;
         }
    }
    else if (param_one->type == PARAM_FUNC && param_two->type == PARAM_FUNC)
    {
        return func_cmp(param_one->params, param_one->ret, param_two->params,
                        param_one->ret, const_cmp);
    }
    else if (param_one->type == PARAM_TOUPLE && param_two->type == PARAM_TOUPLE)
    {
        return param_list_cmp(param_one->dims, param_two->dims, false);
    }
    else
    {
        return PARAM_CMP_FAIL;
    }
}

int param_list_cmp(param_list * param_one, param_list * param_two, bool const_cmp)
{
    if (param_one == NULL && param_two == NULL)
    {
        return PARAM_CMP_SUCC;
    }
    if ((param_one == NULL && param_two != NULL) ||
        (param_one != NULL && param_two == NULL))
    {
        return PARAM_CMP_FAIL;
    }

    if (param_one->count != param_two->count)
    {
        return PARAM_CMP_FAIL;
    }

    param_list_node * param_one_node = param_one->tail;
    param_list_node * param_two_node = param_two->tail;
    while (param_one_node != NULL && param_two_node != NULL)
    {
        param * param_one_value = param_one_node->value;
        param * param_two_value = param_two_node->value;

        if (param_cmp(param_one_value, param_two_value, const_cmp) == PARAM_CMP_FAIL)
        {
            return PARAM_CMP_FAIL;
        }

        param_one_node = param_one_node->next;
        param_two_node = param_two_node->next;
    }

    return PARAM_CMP_SUCC;
}

int func_cmp(param_list * param_list_one, param * ret_one, param_list * param_list_two,
             param * ret_two, bool const_cmp)
{
    if (param_list_cmp(param_list_one, param_list_two, true) == PARAM_CMP_SUCC &&
        param_cmp(ret_one, ret_two, false) == PARAM_CMP_SUCC)
    {
        return PARAM_CMP_SUCC;
    }
    else
    {
        return PARAM_CMP_FAIL;
    }
}

param_list_node * param_list_node_new(param * value)
{
    param_list_node * node = (param_list_node *)malloc(sizeof(param_list_node));

    node->value = value;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void param_list_node_delete(param_list_node * node)
{
    if (node->value)
    {
        param_delete(node->value);
    }
    free(node);
}

param_list * param_list_new()
{
    param_list * list = (param_list *)malloc(sizeof(param_list));

    list->count = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void param_list_delete(param_list * list)
{
    param_list_node * node = list->tail;

    while (node != NULL)
    {
        param_list_node * tmp = node->next;
        param_list_node_delete(node);
        node = tmp;
    }
    free(list);
}

void param_list_add_beg(param_list * list, param * value)
{
    param_list_node * node = param_list_node_new(value);

    list->count++;
    if (list->head == NULL && list->tail == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->prev = node;
        node->next = list->tail;
        list->tail = node;
    }
}

void param_list_add_end(param_list * list, param * value)
{
    param_list_node * node = param_list_node_new(value);

    list->count++;
    if (list->head == NULL && list->tail == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->head->next = node;
        node->prev = list->head;
        list->head = node;
    }
}

param * param_list_find(param_list * list, char * id)
{
    param * ret = NULL;

    param_list_node * node = list->tail;
    while (node != NULL)
    {
        param * value = node->value;
        if (value != NULL)
        {
            if (strcmp(value->id, id) == 0)
            {
                ret = value;
                break; 
            }
        }

        node = node->next;
    }
    
    return ret;
}

param * param_list_get_nth(param_list * list, unsigned int index)
{
    if (list == NULL)
    {
        return NULL;
    }

    unsigned int i = 0;
    param_list_node * node = list->tail;
    for (i = 0; node != NULL && i < index; i++)
    {
        node = node->next;
    }

    if (node != NULL)
    {
        return node->value;
    }
    else
    {
        return NULL;
    }
}

void param_dim_set_array(param_list * dims, param * array)
{
    int index = 0;
    param_list_node * node = dims->tail;
    while (node != NULL)
    {
        param * value = node->value;
        if (value != NULL)
        {
            value->index = index++;
            value->array = array;
        }
        node = node->next;
    }
}

void param_print(param * value)
{
    if (value == NULL)
        return;

    printf("param %s %d %s\n", param_type_str(value->type), value->index,
           value->id);
    param_print(value->ret);
}

void param_list_print(param_list * list)
{
    param_list_node * node = list->tail;
    while (node != NULL)
    {
        param * value = node->value;
        if (value != NULL)
        {
            param_print(value);
        }

        node = node->next;
    }
}

char * param_type_str(param_type type)
{
    switch (type)
    {
    case PARAM_BOOL:
        return "param bool";
    case PARAM_INT:
        return "param int";
    case PARAM_LONG:
        return "param long";
    case PARAM_FLOAT:
        return "param float";
    case PARAM_DOUBLE:
        return "param double";
    case PARAM_ENUMTYPE:
        return "param enumtype";
    case PARAM_CHAR:
        return "param char";
    case PARAM_STRING:
        return "param string";
    case PARAM_VOID:
        return "param void";
    case PARAM_C_PTR:
        return "param c_ptr";
    case PARAM_RECORD:
        return "param record";
    case PARAM_DIM:
        return "param dim";
    case PARAM_RANGE_DIM:
        return "param range dim";
    case PARAM_ARRAY:
        return "param array";
    case PARAM_RANGE:
        return "param range";
    case PARAM_SLICE:
        return "param slice";
    case PARAM_SLICE_DIM:
        return "param slice dim";
    case PARAM_FUNC:
        return "param func";
    case PARAM_TOUPLE:
        return "param touple";
    }
    return "unknown param";
}
