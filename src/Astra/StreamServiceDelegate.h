/* THIS FILE AUTO-GENERATED FROM StreamServiceDelegate.h.lpp. DO NOT EDIT. */
#ifndef STREAMSERVICEDELEGATE_H
#define STREAMSERVICEDELEGATE_H

#include <Astra/astra_types.h>
#include "AstraContext.h"
#include <iostream>

namespace astra {

    class StreamServiceDelegate
    {
    public:

        static astra_status_t streamset_open(void* streamService,
                                             const char* connectionString,
                                             astra_streamsetconnection_t* streamSet)
        {
            return static_cast<AstraContext*>(streamService)->streamset_open(connectionString, *streamSet);
        }

        static astra_status_t streamset_close(void* streamService,
                                              astra_streamsetconnection_t* streamSet)
        {
            return static_cast<AstraContext*>(streamService)->streamset_close(*streamSet);
        }

        static astra_status_t reader_create(void* streamService,
                                            astra_streamsetconnection_t streamSet,
                                            astra_reader_t* reader)
        {
            return static_cast<AstraContext*>(streamService)->reader_create(streamSet, *reader);
        }

        static astra_status_t reader_destroy(void* streamService,
                                             astra_reader_t* reader)
        {
            return static_cast<AstraContext*>(streamService)->reader_destroy(*reader);
        }

        static astra_status_t reader_get_stream(void* streamService,
                                                astra_reader_t reader,
                                                astra_stream_type_t type,
                                                astra_stream_subtype_t subtype,
                                                astra_streamconnection_t* connection)
        {
            return static_cast<AstraContext*>(streamService)->reader_get_stream(reader, type, subtype, *connection);
        }

        static astra_status_t stream_get_description(void* streamService,
                                                     astra_streamconnection_t connection,
                                                     astra_stream_desc_t* description)
        {
            return static_cast<AstraContext*>(streamService)->stream_get_description(connection, description);
        }

        static astra_status_t stream_start(void* streamService,
                                           astra_streamconnection_t connection)
        {
            return static_cast<AstraContext*>(streamService)->stream_start(connection);
        }

        static astra_status_t stream_stop(void* streamService,
                                          astra_streamconnection_t connection)
        {
            return static_cast<AstraContext*>(streamService)->stream_stop(connection);
        }

        static astra_status_t reader_open_frame(void* streamService,
                                                astra_reader_t reader,
                                                int timeoutMillis,
                                                astra_reader_frame_t* frame)
        {
            return static_cast<AstraContext*>(streamService)->reader_open_frame(reader, timeoutMillis, *frame);
        }

        static astra_status_t reader_close_frame(void* streamService,
                                                 astra_reader_frame_t* frame)
        {
            return static_cast<AstraContext*>(streamService)->reader_close_frame(*frame);
        }

        static astra_status_t reader_register_frame_ready_callback(void* streamService,
                                                                   astra_reader_t reader,
                                                                   astra_frame_ready_callback_t callback,
                                                                   void* clientTag,
                                                                   astra_reader_callback_id_t* callbackId)
        {
            return static_cast<AstraContext*>(streamService)->reader_register_frame_ready_callback(reader, callback, clientTag, *callbackId);
        }

        static astra_status_t reader_unregister_frame_ready_callback(void* streamService,
                                                                     astra_reader_callback_id_t* callbackId)
        {
            return static_cast<AstraContext*>(streamService)->reader_unregister_frame_ready_callback(*callbackId);
        }

        static astra_status_t reader_get_frame(void* streamService,
                                               astra_reader_frame_t frame,
                                               astra_stream_type_t type,
                                               astra_stream_subtype_t subtype,
                                               astra_frame_t** subFrame)
        {
            return static_cast<AstraContext*>(streamService)->reader_get_frame(frame, type, subtype, *subFrame);
        }

        static astra_status_t stream_set_parameter(void* streamService,
                                                   astra_streamconnection_t connection,
                                                   astra_parameter_id parameterId,
                                                   size_t inByteLength,
                                                   astra_parameter_data_t inData)
        {
            return static_cast<AstraContext*>(streamService)->stream_set_parameter(connection, parameterId, inByteLength, inData);
        }

        static astra_status_t stream_get_parameter(void* streamService,
                                                   astra_streamconnection_t connection,
                                                   astra_parameter_id parameterId,
                                                   size_t* resultByteLength,
                                                   astra_result_token_t* token)
        {
            return static_cast<AstraContext*>(streamService)->stream_get_parameter(connection, parameterId, *resultByteLength, *token);
        }

        static astra_status_t stream_get_result(void* streamService,
                                                astra_streamconnection_t connection,
                                                astra_result_token_t token,
                                                size_t dataByteLength,
                                                astra_parameter_data_t dataDestination)
        {
            return static_cast<AstraContext*>(streamService)->stream_get_result(connection, token, dataByteLength, dataDestination);
        }

        static astra_status_t stream_invoke(void* streamService,
                                            astra_streamconnection_t connection,
                                            astra_command_id commandId,
                                            size_t inByteLength,
                                            astra_parameter_data_t inData,
                                            size_t* resultByteLength,
                                            astra_result_token_t* token)
        {
            return static_cast<AstraContext*>(streamService)->stream_invoke(connection, commandId, inByteLength, inData, *resultByteLength, *token);
        }

        static astra_status_t temp_update(void* streamService)
        {
            return static_cast<AstraContext*>(streamService)->temp_update();
        }
    };
}

#endif /* STREAMSERVICEDELEGATE_H */
