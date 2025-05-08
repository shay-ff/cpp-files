# Import necessary libraries
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import plotly.express as px
import streamlit as st


# Load the Data
@st.cache_data
def load_data():
    df = pd.read_csv('Data Set- Inc5000 Company List_2014.csv', sep=',')
    return df


df = load_data()

# Dashboard Title
st.title('Interactive Tableau/Power BI-like Dashboard')

# Sidebar Elements for Filtering
st.sidebar.header('Filters')
industries = st.sidebar.multiselect('Select Industries', df['industry'].unique(), default=df['industry'].unique())

# Apply Filters
filtered_df = df[df['industry'].isin(industries)]

# ---- Data Exploration Section ----
st.subheader('Data Exploration')
st.write('**Dataset Overview**')
st.write(df.head())

st.write('**Data Summary:**')
st.write(df.describe())

st.write('**Missing Values:**')
st.write(df.isnull().sum())

# ---- Static Visualizations with matplotlib and seaborn ----
st.subheader('Static Visualizations')
st.write('**Bar Chart: Top 10 Industries by Number of Companies**')
top_industries = df['industry'].value_counts().nlargest(10)

fig, ax = plt.subplots(figsize=(8, 6))
top_industries.plot(kind='bar', ax=ax)
ax.set_title('Top 10 Industries by Number of Companies')
ax.set_xlabel('Industry')
ax.set_ylabel('Number of Companies')
st.pyplot(fig)

st.write('**Scatter Plot: Revenue vs. Growth Rate**')
fig, ax = plt.subplots(figsize=(10, 6))
sns.scatterplot(data=filtered_df, x='revenue', y='Growth Rate', hue='industry', ax=ax)
ax.set_title('Revenue vs. Growth Rate by Industry')
ax.set_xlabel('Revenue')
ax.set_ylabel('Growth Rate')
plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
st.pyplot(fig)

# ---- Interactive Visualizations with Plotly ----
st.subheader('Interactive Visualizations')

# Bar Chart
st.write('**Revenue by Industry**')
fig1 = px.bar(filtered_df, x='Industry', y='Revenue', title='Revenue by Industry', color='Revenue', height=500)
st.plotly_chart(fig1)

# Scatter Plot
st.write('**Interactive Scatter Plot: Revenue vs Growth Rate**')
fig2 = px.scatter(filtered_df, x='Revenue', y='Growth Rate', color='Industry', size='Revenue',
                  hover_data=['Company Name', 'City'], height=600)
st.plotly_chart(fig2)

# ---- Additional Sidebar and Features ----
st.sidebar.subheader('Download Filtered Data')


# Provide download functionality for filtered data
@st.cache_data
def convert_to_csv(data):
    return data.to_csv(index=False).encode('utf-8')


csv = convert_to_csv(filtered_df)
st.sidebar.download_button(label='Download Filtered Data as CSV', data=csv, file_name='filtered_data.csv',
                           mime='text/csv')

