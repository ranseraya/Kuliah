// components/TodoItem.js
import React from 'react';
import { View, Text, StyleSheet, Button, TouchableOpacity } from 'react-native';

const styles = StyleSheet.create({
    todoitem: {
        display: 'flex',
        justifyContent: 'space-between',
        alignItems: 'center',
        marginBottom: 8,
        padding: 8,
        border: 1,
        borderColor: '#ddd',
        borderRadius: 4,
    },
    todoitemtext: {
        // flex: 1,
        marginRight: 8,
        color: '#333',
    },
    completed: {
        textDecorationLine: 'line-through',
        color: '#888',
    },
    deletebutton: {
        backgroundColor: '#D04848',
        color: '#fff',
        padding: 4,
        border: 'none',
        borderRadius: 4,
        cursor: 'pointer',
    },
    completebutton: {
        backgroundColor: '#F3B95F',
        color: '#000',
        padding: 4,
        border: 'none',
        borderRadius: 4,
        cursor: 'pointer',
    },
});

const TodoItem = ({ task, deleteTask, toggleCompleted }) => {
    return (
        <View style={styles.todoitem}>
            <Text style={[styles.todoitemtext, task.completed && styles.completed]}>
                {task.text}
            </Text>
            <TouchableOpacity style={styles.deletebutton} onPress={() => deleteTask(task.id)}>
                <Text style={{ color: '#fff'}}>Delete</Text>
            </TouchableOpacity>
            <TouchableOpacity style={styles.completebutton} onPress={() => toggleCompleted(task.id)}>
                <Text style={{ color: '#fff'}}>{task.completed && 'completed'}{!task.completed && 'uncompleted'}</Text>
            </TouchableOpacity>
        </View>
    )
}

export default TodoItem;