/* THIS FILE AUTO-GENERATED FROM plugin_callbacks.h.lpp. DO NOT EDIT. */
#ifndef PLUGIN_CALLBACKS_H
#define PLUGIN_CALLBACKS_H

#include <Astra/astra_capi.h>

typedef void(*set_parameter_callback_t)(void*,
                                        astra_streamconnection_t,
                                        astra_parameter_id,
                                        size_t,
                                        astra_parameter_data_t);

typedef void(*get_parameter_callback_t)(void*,
                                        astra_streamconnection_t,
                                        astra_parameter_id,
                                        astra_parameter_bin_t*);

typedef void(*invoke_callback_t)(void*,
                                 astra_streamconnection_t,
                                 astra_command_id,
                                 size_t,
                                 astra_parameter_data_t,
                                 astra_parameter_bin_t*);

typedef void(*connection_added_callback_t)(void*,
                                           astra_stream_t,
                                           astra_streamconnection_t);

typedef void(*connection_removed_callback_t)(void*,
                                             astra_stream_t,
                                             astra_bin_t,
                                             astra_streamconnection_t);


typedef void(*stream_registered_callback_t)(void*,
                                            astra_streamset_t,
                                            astra_stream_t,
                                            astra_stream_desc_t);

typedef void(*stream_unregistering_callback_t)(void*,
                                               astra_streamset_t,
                                               astra_stream_t,
                                               astra_stream_desc_t);

typedef void(*host_event_callback_t)(void*,
                                     astra_event_id,
                                     const void*,
                                     size_t);

struct stream_callbacks_t {
    void* context;
    set_parameter_callback_t set_parameter_callback;
    get_parameter_callback_t get_parameter_callback;
    invoke_callback_t invoke_callback;
    connection_added_callback_t connection_added_callback;
    connection_removed_callback_t connection_removed_callback;
};

#endif /* PLUGIN_CALLBACKS_H */
